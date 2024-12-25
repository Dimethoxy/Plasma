#include "CustomLabel.h"
#include <JuceHeader.h>

class ValueEditor
  : public Component
  , public TextEditor::Listener
{
public:
  ValueEditor()
    : textbox("Default Value", FontSizes::Main, Justification::centredLeft)
  {
    addAndMakeVisible(textbox);
  }

  void resized() override { textbox.setBounds(getLocalBounds()); }

  void paint(Graphics& g) override { g.fillAll(Colours::red); }

private:
  CustomTextbox textbox;
};