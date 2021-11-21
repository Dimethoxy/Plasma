#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PlasmaAudioProcessorEditor::PlasmaAudioProcessorEditor (PlasmaAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
       setSize (600, 300);
}

PlasmaAudioProcessorEditor::~PlasmaAudioProcessorEditor()
{
}

//==============================================================================
void PlasmaAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colour(35, 35, 35));
}

void PlasmaAudioProcessorEditor::resized()
{
    int columns = 7;
}

void PlasmaAudioProcessorEditor::sliderValueChanged (Slider* slider)
{

}
