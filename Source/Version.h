#pragma once
//=============================================================================================
#include <JuceHeader.h>
//=============================================================================================
enum Target
{
  Windows,
  Mac,
  Linux
};
//=============================================================================================
const Target OS = Windows;
//=============================================================================================
class VersionManager : public juce::AsyncUpdater
{
public:
  VersionManager()
    : juce::AsyncUpdater()
  {
  }
  void handleAsyncUpdate()
  {
    t = std::make_unique<std::thread>([this] { updateVersion(); });
    t->detach();
  }
  void updateVersion()
  {
    const bool response = isUpToDate(ProjectInfo::versionString);
    juce::String link = "";
    if (response) {
      link = getDownloadLink();
    }
    if (killFlag.load()) {
      return;
    } else {
      downloadLink = link;
      isLatest.store(response);
      finished.store(true);
    }
  }

  std::atomic<bool> killFlag{ false };
  std::atomic<bool> isLatest{ false };
  std::atomic<bool> finished{ false };
  juce::String downloadLink{ "" };

private:
  std::unique_ptr<std::thread> t;

  juce::URL createURL(const juce::String& apiEndpoint)
  {
    // Replace "YOUR_API_URL_HERE" with the actual URL of your web API
    return juce::URL("https://api.dimethoxy.com/" + apiEndpoint);
  }

  juce::String sendRequest(const juce::String& apiEndpoint)
  {
    juce::URL url = createURL(apiEndpoint);

    // Send a GET request to the specified URL
    juce::String responseString = url.readEntireTextStream();

    return responseString;
  }

  juce::String extractVersionNumber(const juce::String& payload)
  {
    juce::var responseJSON = juce::JSON::parse(payload);
    juce::String version = responseJSON["version"].toString();
    return version;
  }

  bool isUpToDate(const juce::String& currentVersion)
  {
    try {
      juce::String apiResponse = sendRequest("version?product=plasma");
      juce::String latestVersion = extractVersionNumber(apiResponse);
      bool isLatest = (latestVersion == currentVersion) || latestVersion == "";
      return !isLatest;
    } catch (...) {
      return true;
    }
  }

  juce::String getDownloadLink()
  {
    juce::String osString;
    if (OS == Windows) {
      osString = "windows";
    } else if (OS == Mac) {
      osString = "mac";
    } else {
      osString = "archlinux";
    }
    juce::String apiResponse =
      sendRequest("download?product=plasma&os=" + osString);
    juce::var responseJSON = juce::JSON::parse(apiResponse);
    return responseJSON["download_url"].toString();
  }
};