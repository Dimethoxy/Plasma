#include "ResponseCurveComponent.h"

ResponseCurveComponent::ResponseCurveComponent(PlasmaAudioProcessor& p)
  : audioProcessor(p)
{
  // Listen to parameter changes
  const auto& params = audioProcessor.getParameters();
  for (auto param : params) {
    param->addListener(this);
  }
  startTimer(60);
}

ResponseCurveComponent::~ResponseCurveComponent()
{
  const auto& params = audioProcessor.getParameters();
  for (auto param : params) {
    param->removeListener(this);
  }
}

void
ResponseCurveComponent::parameterValueChanged(int parameterIndex,
                                              float newValue)
{
  parametersChanged.set(true);
}

void
ResponseCurveComponent::timerCallback()
{
  if (parametersChanged.compareAndSetBool(false, true)) {
    update();
  }
}

void
ResponseCurveComponent::update()
{
  // Update Monochain
  auto chainSettings = getChainSettings(audioProcessor.apvts);

  // Coefficients
  auto highPassCoefficients =
    makeHighPassFilter(chainSettings, audioProcessor.getSampleRate());
  auto highPassResonanceCoefficients =
    makeHighPassResonance(chainSettings, audioProcessor.getSampleRate());
  auto peakCoefficients =
    makePeakFilter(chainSettings, audioProcessor.getSampleRate(), 0.0);
  auto dualPeakACoefficients = makeDualPeakFilter(
    chainSettings, audioProcessor.getSampleRate(), chainSettings.dualPeakWidth);
  auto dualPeakBCoefficients =
    makeDualPeakFilter(chainSettings,
                       audioProcessor.getSampleRate(),
                       -chainSettings.dualPeakWidth);
  auto lowPassResonanceCoefficients =
    makeLowPassResonance(chainSettings, audioProcessor.getSampleRate());
  auto lowPassCoefficients =
    makeLowPassFilter(chainSettings, audioProcessor.getSampleRate());

  // Updates
  updatePassFilter(monoChain.get<ChainPositions::HighPass>(),
                   highPassCoefficients,
                   chainSettings.highPassSlope);
  updateCoefficients(
    monoChain.get<ChainPositions::HighPassResonance>().coefficients,
    highPassResonanceCoefficients);
  updateCoefficients(monoChain.get<ChainPositions::Peak>().coefficients,
                     peakCoefficients);
  updateCoefficients(monoChain.get<ChainPositions::DualPeakA>().coefficients,
                     dualPeakACoefficients);
  updateCoefficients(monoChain.get<ChainPositions::DualPeakB>().coefficients,
                     dualPeakBCoefficients);
  updateCoefficients(
    monoChain.get<ChainPositions::LowPassResonance>().coefficients,
    lowPassResonanceCoefficients);
  updatePassFilter(monoChain.get<ChainPositions::LowPass>(),
                   lowPassCoefficients,
                   chainSettings.lowPassSlope);

  // Repaint
  repaint();
}

void
ResponseCurveComponent::paint(juce::Graphics& g)
{
  using namespace juce;

  // bounds
  auto bounds = getBounds();
  auto lineSize = bounds.getHeight() / 100;
  lineSize = (lineSize < 1.0f) ? 1.0f : lineSize;

  // Screen
  auto x = padding;
  auto y = padding;
  auto w = bounds.getWidth() - padding;
  auto h = bounds.getHeight() - padding;

  // g.setColour(Colours::black);
  // g.fillRect(x, y, w, h);
  auto& highpass = monoChain.get<ChainPositions::HighPass>();
  auto& highpassResonance = monoChain.get<ChainPositions::HighPassResonance>();
  auto& peak = monoChain.get<ChainPositions::Peak>();
  auto& dualPeakA = monoChain.get<ChainPositions::DualPeakA>();
  auto& dualPeakB = monoChain.get<ChainPositions::DualPeakB>();
  auto& lowpass = monoChain.get<ChainPositions::LowPass>();
  auto& lowpassResonance = monoChain.get<ChainPositions::LowPassResonance>();

  auto sampleRate = audioProcessor.getSampleRate();

  std::vector<double> mags;
  mags.resize(w);
  for (int i = 0; i < w; ++i) {
    // Magnitude
    double mag = 1.f;
    auto freq = mapToLog10(double(i) / double(w), 20.0, 20000.0);

    // Highpass
    if (!highpass.isBypassed<0>())
      mag *= highpass.get<0>().coefficients->getMagnitudeForFrequency(
        freq, sampleRate);
    if (!highpass.isBypassed<1>())
      mag *= highpass.get<1>().coefficients->getMagnitudeForFrequency(
        freq, sampleRate);
    if (!highpass.isBypassed<2>())
      mag *= highpass.get<2>().coefficients->getMagnitudeForFrequency(
        freq, sampleRate);
    if (!highpass.isBypassed<3>())
      mag *= highpass.get<3>().coefficients->getMagnitudeForFrequency(
        freq, sampleRate);
    if (!highpass.isBypassed<4>())
      mag *= highpass.get<4>().coefficients->getMagnitudeForFrequency(
        freq, sampleRate);
    if (!highpass.isBypassed<5>())
      mag *= highpass.get<5>().coefficients->getMagnitudeForFrequency(
        freq, sampleRate);
    if (!highpass.isBypassed<6>())
      mag *= highpass.get<6>().coefficients->getMagnitudeForFrequency(
        freq, sampleRate);
    if (!highpass.isBypassed<7>())
      mag *= highpass.get<7>().coefficients->getMagnitudeForFrequency(
        freq, sampleRate);

    // Highpass Resonance
    if (!monoChain.isBypassed<ChainPositions::HighPassResonance>())
      mag *= highpassResonance.coefficients->getMagnitudeForFrequency(
        freq, sampleRate);

    // Peak
    if (!monoChain.isBypassed<ChainPositions::Peak>())
      mag *= peak.coefficients->getMagnitudeForFrequency(freq, sampleRate);

    // Dual Peak A
    if (!monoChain.isBypassed<ChainPositions::DualPeakA>())
      mag *= dualPeakA.coefficients->getMagnitudeForFrequency(freq, sampleRate);

    // Dual Peak B
    if (!monoChain.isBypassed<ChainPositions::DualPeakB>())
      mag *= dualPeakB.coefficients->getMagnitudeForFrequency(freq, sampleRate);

    // Lowpass
    if (!lowpass.isBypassed<0>())
      mag *= lowpass.get<0>().coefficients->getMagnitudeForFrequency(
        freq, sampleRate);
    if (!lowpass.isBypassed<1>())
      mag *= lowpass.get<1>().coefficients->getMagnitudeForFrequency(
        freq, sampleRate);
    if (!lowpass.isBypassed<2>())
      mag *= lowpass.get<2>().coefficients->getMagnitudeForFrequency(
        freq, sampleRate);
    if (!lowpass.isBypassed<3>())
      mag *= lowpass.get<3>().coefficients->getMagnitudeForFrequency(
        freq, sampleRate);
    if (!lowpass.isBypassed<4>())
      mag *= lowpass.get<4>().coefficients->getMagnitudeForFrequency(
        freq, sampleRate);
    if (!lowpass.isBypassed<5>())
      mag *= lowpass.get<5>().coefficients->getMagnitudeForFrequency(
        freq, sampleRate);
    if (!lowpass.isBypassed<6>())
      mag *= lowpass.get<6>().coefficients->getMagnitudeForFrequency(
        freq, sampleRate);
    if (!lowpass.isBypassed<7>())
      mag *= lowpass.get<7>().coefficients->getMagnitudeForFrequency(
        freq, sampleRate);

    // Lowpass Resonance
    if (!monoChain.isBypassed<ChainPositions::LowPassResonance>())
      mag *= lowpassResonance.coefficients->getMagnitudeForFrequency(
        freq, sampleRate);

    // Write
    mags[i] = Decibels::gainToDecibels(mag);
  }

  Path responseCurve;
  const double outputMin = y + h;
  const double outputMax = y;
  auto map = [outputMin, outputMax](double input) {
    return jmap(input, -48.0, 48.0, outputMin, outputMax);
  };

  responseCurve.startNewSubPath(x, map(mags.front()));
  for (size_t i = 1; i < mags.size(); ++i) {
    responseCurve.lineTo(x + i, map(mags[i]));
  }
  g.setColour(color);
  g.strokePath(responseCurve, PathStrokeType(lineSize));
}

void
ResponseCurveComponent::setPadding(float newPadding)
{
  padding = newPadding;
}

void
ResponseCurveComponent::setColor(Colour c)
{
  color = c;
}
