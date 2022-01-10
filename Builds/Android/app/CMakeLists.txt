# Automatically generated makefile, created by the Projucer
# Don't edit this file! Your changes will be overwritten when you re-save the Projucer project!

cmake_minimum_required(VERSION 3.4.1)

set(BINARY_NAME "juce_jni")

set(OBOE_DIR "G:/Code/JUCE/JUCE/modules/juce_audio_devices/native/oboe")

add_subdirectory (${OBOE_DIR} ./oboe)

add_library("cpufeatures" STATIC "${ANDROID_NDK}/sources/android/cpufeatures/cpu-features.c")
set_source_files_properties("${ANDROID_NDK}/sources/android/cpufeatures/cpu-features.c" PROPERTIES COMPILE_FLAGS "-Wno-sign-conversion -Wno-gnu-statement-expression")

add_definitions("-DJUCE_ANDROID=1" "-DJUCE_ANDROID_API_VERSION=16" "-DJUCE_PUSH_NOTIFICATIONS=1" "-DJUCE_PUSH_NOTIFICATIONS_ACTIVITY=\"com/rmsl/juce/JuceActivity\"" "-DJUCER_ANDROIDSTUDIO_7F0E4A25=1" "-DJUCE_APP_VERSION=1.0.0" "-DJUCE_APP_VERSION_HEX=0x10000")

include_directories( AFTER
    "../../../JuceLibraryCode"
    "G:/Code/JUCE/JUCE/modules"
    "${ANDROID_NDK}/sources/android/cpufeatures"
)

enable_language(ASM)

if(JUCE_BUILD_CONFIGURATION MATCHES "DEBUG")
    add_definitions("-DJUCE_DISPLAY_SPLASH_SCREEN=0" "-DJUCE_USE_DARK_SPLASH_SCREEN=1" "-DJUCE_PROJUCER_VERSION=0x60102" "-DJUCE_MODULE_AVAILABLE_juce_audio_basics=1" "-DJUCE_MODULE_AVAILABLE_juce_audio_devices=1" "-DJUCE_MODULE_AVAILABLE_juce_audio_formats=1" "-DJUCE_MODULE_AVAILABLE_juce_audio_plugin_client=1" "-DJUCE_MODULE_AVAILABLE_juce_audio_processors=1" "-DJUCE_MODULE_AVAILABLE_juce_audio_utils=1" "-DJUCE_MODULE_AVAILABLE_juce_core=1" "-DJUCE_MODULE_AVAILABLE_juce_data_structures=1" "-DJUCE_MODULE_AVAILABLE_juce_dsp=1" "-DJUCE_MODULE_AVAILABLE_juce_events=1" "-DJUCE_MODULE_AVAILABLE_juce_graphics=1" "-DJUCE_MODULE_AVAILABLE_juce_gui_basics=1" "-DJUCE_MODULE_AVAILABLE_juce_gui_extra=1" "-DJUCE_GLOBAL_MODULE_SETTINGS_INCLUDED=1" "-DJUCE_VST3_CAN_REPLACE_VST2=0" "-DJUCE_STRICT_REFCOUNTEDPOINTER=1" "-DJucePlugin_Build_VST=0" "-DJucePlugin_Build_VST3=1" "-DJucePlugin_Build_AU=0" "-DJucePlugin_Build_AUv3=0" "-DJucePlugin_Build_RTAS=0" "-DJucePlugin_Build_AAX=0" "-DJucePlugin_Build_Standalone=0" "-DJucePlugin_Build_Unity=0" "-DJucePlugin_Enable_IAA=0" "-DJucePlugin_Name=\"Plasma\"" "-DJucePlugin_Desc=\"Plasma\"" "-DJucePlugin_Manufacturer=\"yourcompany\"" "-DJucePlugin_ManufacturerWebsite=\"\"" "-DJucePlugin_ManufacturerEmail=\"\"" "-DJucePlugin_ManufacturerCode=0x4d616e75" "-DJucePlugin_PluginCode=0x516d6638" "-DJucePlugin_IsSynth=0" "-DJucePlugin_WantsMidiInput=0" "-DJucePlugin_ProducesMidiOutput=0" "-DJucePlugin_IsMidiEffect=0" "-DJucePlugin_EditorRequiresKeyboardFocus=0" "-DJucePlugin_Version=1.0.0" "-DJucePlugin_VersionCode=0x10000" "-DJucePlugin_VersionString=\"1.0.0\"" "-DJucePlugin_VSTUniqueID=JucePlugin_PluginCode" "-DJucePlugin_VSTCategory=kPlugCategEffect" "-DJucePlugin_Vst3Category=\"Fx\"" "-DJucePlugin_AUMainType='aufx'" "-DJucePlugin_AUSubType=JucePlugin_PluginCode" "-DJucePlugin_AUExportPrefix=PlasmaAU" "-DJucePlugin_AUExportPrefixQuoted=\"PlasmaAU\"" "-DJucePlugin_AUManufacturerCode=JucePlugin_ManufacturerCode" "-DJucePlugin_CFBundleIdentifier=com.yourcompany.Plasma" "-DJucePlugin_RTASCategory=0" "-DJucePlugin_RTASManufacturerCode=JucePlugin_ManufacturerCode" "-DJucePlugin_RTASProductId=JucePlugin_PluginCode" "-DJucePlugin_RTASDisableBypass=0" "-DJucePlugin_RTASDisableMultiMono=0" "-DJucePlugin_AAXIdentifier=com.yourcompany.Plasma" "-DJucePlugin_AAXManufacturerCode=JucePlugin_ManufacturerCode" "-DJucePlugin_AAXProductId=JucePlugin_PluginCode" "-DJucePlugin_AAXCategory=0" "-DJucePlugin_AAXDisableBypass=0" "-DJucePlugin_AAXDisableMultiMono=0" "-DJucePlugin_IAAType=0x61757278" "-DJucePlugin_IAASubType=JucePlugin_PluginCode" "-DJucePlugin_IAAName=\"yourcompany: Plasma\"" "-DJucePlugin_VSTNumMidiInputs=16" "-DJucePlugin_VSTNumMidiOutputs=16" "-DJUCE_STANDALONE_APPLICATION=JucePlugin_Build_Standalone" "-DJUCER_ANDROIDSTUDIO_7F0E4A25=1" "-DJUCE_APP_VERSION=1.0.0" "-DJUCE_APP_VERSION_HEX=0x10000" "-DDEBUG=1" "-D_DEBUG=1")
elseif(JUCE_BUILD_CONFIGURATION MATCHES "RELEASE")
    add_definitions("-DJUCE_DISPLAY_SPLASH_SCREEN=0" "-DJUCE_USE_DARK_SPLASH_SCREEN=1" "-DJUCE_PROJUCER_VERSION=0x60102" "-DJUCE_MODULE_AVAILABLE_juce_audio_basics=1" "-DJUCE_MODULE_AVAILABLE_juce_audio_devices=1" "-DJUCE_MODULE_AVAILABLE_juce_audio_formats=1" "-DJUCE_MODULE_AVAILABLE_juce_audio_plugin_client=1" "-DJUCE_MODULE_AVAILABLE_juce_audio_processors=1" "-DJUCE_MODULE_AVAILABLE_juce_audio_utils=1" "-DJUCE_MODULE_AVAILABLE_juce_core=1" "-DJUCE_MODULE_AVAILABLE_juce_data_structures=1" "-DJUCE_MODULE_AVAILABLE_juce_dsp=1" "-DJUCE_MODULE_AVAILABLE_juce_events=1" "-DJUCE_MODULE_AVAILABLE_juce_graphics=1" "-DJUCE_MODULE_AVAILABLE_juce_gui_basics=1" "-DJUCE_MODULE_AVAILABLE_juce_gui_extra=1" "-DJUCE_GLOBAL_MODULE_SETTINGS_INCLUDED=1" "-DJUCE_VST3_CAN_REPLACE_VST2=0" "-DJUCE_STRICT_REFCOUNTEDPOINTER=1" "-DJucePlugin_Build_VST=0" "-DJucePlugin_Build_VST3=1" "-DJucePlugin_Build_AU=0" "-DJucePlugin_Build_AUv3=0" "-DJucePlugin_Build_RTAS=0" "-DJucePlugin_Build_AAX=0" "-DJucePlugin_Build_Standalone=0" "-DJucePlugin_Build_Unity=0" "-DJucePlugin_Enable_IAA=0" "-DJucePlugin_Name=\"Plasma\"" "-DJucePlugin_Desc=\"Plasma\"" "-DJucePlugin_Manufacturer=\"yourcompany\"" "-DJucePlugin_ManufacturerWebsite=\"\"" "-DJucePlugin_ManufacturerEmail=\"\"" "-DJucePlugin_ManufacturerCode=0x4d616e75" "-DJucePlugin_PluginCode=0x516d6638" "-DJucePlugin_IsSynth=0" "-DJucePlugin_WantsMidiInput=0" "-DJucePlugin_ProducesMidiOutput=0" "-DJucePlugin_IsMidiEffect=0" "-DJucePlugin_EditorRequiresKeyboardFocus=0" "-DJucePlugin_Version=1.0.0" "-DJucePlugin_VersionCode=0x10000" "-DJucePlugin_VersionString=\"1.0.0\"" "-DJucePlugin_VSTUniqueID=JucePlugin_PluginCode" "-DJucePlugin_VSTCategory=kPlugCategEffect" "-DJucePlugin_Vst3Category=\"Fx\"" "-DJucePlugin_AUMainType='aufx'" "-DJucePlugin_AUSubType=JucePlugin_PluginCode" "-DJucePlugin_AUExportPrefix=PlasmaAU" "-DJucePlugin_AUExportPrefixQuoted=\"PlasmaAU\"" "-DJucePlugin_AUManufacturerCode=JucePlugin_ManufacturerCode" "-DJucePlugin_CFBundleIdentifier=com.yourcompany.Plasma" "-DJucePlugin_RTASCategory=0" "-DJucePlugin_RTASManufacturerCode=JucePlugin_ManufacturerCode" "-DJucePlugin_RTASProductId=JucePlugin_PluginCode" "-DJucePlugin_RTASDisableBypass=0" "-DJucePlugin_RTASDisableMultiMono=0" "-DJucePlugin_AAXIdentifier=com.yourcompany.Plasma" "-DJucePlugin_AAXManufacturerCode=JucePlugin_ManufacturerCode" "-DJucePlugin_AAXProductId=JucePlugin_PluginCode" "-DJucePlugin_AAXCategory=0" "-DJucePlugin_AAXDisableBypass=0" "-DJucePlugin_AAXDisableMultiMono=0" "-DJucePlugin_IAAType=0x61757278" "-DJucePlugin_IAASubType=JucePlugin_PluginCode" "-DJucePlugin_IAAName=\"yourcompany: Plasma\"" "-DJucePlugin_VSTNumMidiInputs=16" "-DJucePlugin_VSTNumMidiOutputs=16" "-DJUCE_STANDALONE_APPLICATION=JucePlugin_Build_Standalone" "-DJUCER_ANDROIDSTUDIO_7F0E4A25=1" "-DJUCE_APP_VERSION=1.0.0" "-DJUCE_APP_VERSION_HEX=0x10000" "-DNDEBUG=1")
else()
    message( FATAL_ERROR "No matching build-configuration found." )
endif()

add_library( ${BINARY_NAME}

    SHARED

    "../../../Source/PlasmaLabel.cpp"
    "../../../Source/PlasmaLabel.h"
    "../../../Source/CustomTextButton.cpp"
    "../../../Source/CustomTextButton.h"
    "../../../Source/CustomLabel.cpp"
    "../../../Source/CustomLabel.h"
    "../../../Source/LoudnessMeterComponent.cpp"
    "../../../Source/LoudnessMeterComponent.h"
    "../../../Source/ResponseCurveComponent.cpp"
    "../../../Source/ResponseCurveComponent.h"
    "../../../Source/CustomRotarySlider.cpp"
    "../../../Source/CustomRotarySlider.h"
    "../../../Source/CustomLookAndFeel.cpp"
    "../../../Source/CustomLookAndFeel.h"
    "../../../Source/PluginProcessor.cpp"
    "../../../Source/PluginProcessor.h"
    "../../../Source/PluginEditor.cpp"
    "../../../Source/PluginEditor.h"
    "../../../Resources/Sedgwick_Ave_Display/OFL.txt"
    "../../../Resources/Sedgwick_Ave_Display/SedgwickAveDisplay-Regular.ttf"
    "../../../Resources/Sedgwick_Ave/OFL.txt"
    "../../../Resources/Sedgwick_Ave/SedgwickAve-Regular.ttf"
    "../../../Resources/Poppins/OFL.txt"
    "../../../Resources/Poppins/Poppins-Black.ttf"
    "../../../Resources/Poppins/Poppins-BlackItalic.ttf"
    "../../../Resources/Poppins/Poppins-Bold.ttf"
    "../../../Resources/Poppins/Poppins-BoldItalic.ttf"
    "../../../Resources/Poppins/Poppins-ExtraBold.ttf"
    "../../../Resources/Poppins/Poppins-ExtraBoldItalic.ttf"
    "../../../Resources/Poppins/Poppins-ExtraLight.ttf"
    "../../../Resources/Poppins/Poppins-ExtraLightItalic.ttf"
    "../../../Resources/Poppins/Poppins-Italic.ttf"
    "../../../Resources/Poppins/Poppins-Light.ttf"
    "../../../Resources/Poppins/Poppins-LightItalic.ttf"
    "../../../Resources/Poppins/Poppins-Medium.ttf"
    "../../../Resources/Poppins/Poppins-MediumItalic.ttf"
    "../../../Resources/Poppins/Poppins-Regular.ttf"
    "../../../Resources/Poppins/Poppins-SemiBold.ttf"
    "../../../Resources/Poppins/Poppins-SemiBoldItalic.ttf"
    "../../../Resources/Poppins/Poppins-Thin.ttf"
    "../../../Resources/Poppins/Poppins-ThinItalic.ttf"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/audio_play_head/juce_AudioPlayHead.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_AudioProcessLoadMeasurer.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_AudioProcessLoadMeasurer.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_AudioSampleBuffer.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMP.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPacket.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPackets.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPConversion.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPConverters.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPDispatcher.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPFactory.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPIterator.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPMidi1ToBytestreamTranslator.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPMidi1ToMidi2DefaultTranslator.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPMidi1ToMidi2DefaultTranslator.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPProtocols.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPReceiver.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPSysEx7.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPSysEx7.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPTests.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPUtils.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPUtils.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPView.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPView.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiDataConcatenator.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/native/juce_mac_CoreAudioLayouts.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_AudioSource.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_PositionableAudioSource.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_ADSR.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_ADSR_test.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_Decibels.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_GenericInterpolator.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_IIRFilter.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_IIRFilter.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_Interpolators.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_Interpolators.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_LagrangeInterpolator.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_Reverb.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_SmoothedValue.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_SmoothedValue.h"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_WindowedSincInterpolator.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/juce_audio_basics.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/juce_audio_basics.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_basics/juce_audio_basics.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/audio_io/juce_SystemAudioVolume.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPBytestreamInputHandler.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPTests.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPU32InputHandler.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/midi_io/juce_MidiDevices.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/midi_io/juce_MidiDevices.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/AudioStream.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/AudioStreamBase.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/AudioStreamBuilder.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/AudioStreamCallback.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/Definitions.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/LatencyTuner.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/Oboe.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/ResultWithValue.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/StabilizedCallback.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/Utilities.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/Version.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AAudioExtensions.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AAudioLoader.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AAudioLoader.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AudioStreamAAudio.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AudioStreamAAudio.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioClock.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioSourceCaller.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioSourceCaller.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioStream.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioStreamBuilder.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/DataConversionFlowGraph.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/DataConversionFlowGraph.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/FilterAudioStream.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/FilterAudioStream.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockAdapter.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockAdapter.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockReader.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockReader.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockWriter.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockWriter.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/LatencyTuner.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/MonotonicCounter.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/OboeDebug.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/QuirksManager.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/QuirksManager.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceFloatCaller.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceFloatCaller.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceI16Caller.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceI16Caller.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceI24Caller.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceI24Caller.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceI32Caller.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceI32Caller.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/StabilizedCallback.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/Trace.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/Trace.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/Utilities.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/Version.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoBuffer.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoBuffer.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoController.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoController.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoControllerBase.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoControllerBase.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoControllerIndirect.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoControllerIndirect.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/HyperbolicCosineWindow.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/IntegerRatio.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/IntegerRatio.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/KaiserWindow.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/LinearResampler.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/LinearResampler.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/MultiChannelResampler.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/MultiChannelResampler.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResampler.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResampler.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerMono.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerMono.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerStereo.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerStereo.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResampler.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResampler.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResamplerStereo.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResamplerStereo.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ChannelCountConverter.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ChannelCountConverter.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ClipToRange.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ClipToRange.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/FlowGraphNode.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/FlowGraphNode.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/FlowgraphUtilities.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ManyToMultiConverter.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ManyToMultiConverter.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/MonoToMultiConverter.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/MonoToMultiConverter.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/MultiToMonoConverter.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/MultiToMonoConverter.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/RampLinear.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/RampLinear.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SampleRateConverter.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SampleRateConverter.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkFloat.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkFloat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI16.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI16.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI24.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI24.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI32.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI32.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceFloat.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceFloat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI16.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI16.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI24.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI24.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI32.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI32.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioInputStreamOpenSLES.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioInputStreamOpenSLES.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioOutputStreamOpenSLES.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioOutputStreamOpenSLES.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioStreamBuffered.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioStreamBuffered.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioStreamOpenSLES.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioStreamOpenSLES.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/EngineOpenSLES.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/EngineOpenSLES.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/OpenSLESUtilities.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/OpenSLESUtilities.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/OutputMixerOpenSLES.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/OutputMixerOpenSLES.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/CMakeLists.txt"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/README.md"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_android_Audio.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_android_HighPerformanceAudioHelpers.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_android_Midi.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_android_Oboe.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_android_OpenSL.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_linux_ALSA.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_linux_Bela.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_linux_JackAudio.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_linux_Midi.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_mac_CoreAudio.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_mac_CoreMidi.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_win32_ASIO.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_win32_DirectSound.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_win32_Midi.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_win32_WASAPI.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.h"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/juce_audio_devices.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/juce_audio_devices.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_devices/juce_audio_devices.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/all.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitmath.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitreader.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitwriter.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/cpu.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/crc.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/fixed.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/float.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/format.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/lpc.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/md5.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/memory.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/metadata.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder_framing.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/window.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/all.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_decoder.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_encoder.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitmath.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitreader.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitwriter.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/cpu.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/crc.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/fixed.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/float.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/format.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/lpc_flac.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/md5.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/memory.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_decoder.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder_framing.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/window_flac.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/all.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/alloc.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/assert.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/callback.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/compat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/endswap.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/export.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/Flac Licence.txt"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/format.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/metadata.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/ordinals.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/stream_decoder.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/stream_encoder.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/win_utf8_io.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/coupled/res_books_51.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/coupled/res_books_stereo.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/floor/floor_books.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/uncoupled/res_books_uncoupled.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/floor_all.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_8.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_11.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_16.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_44.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_8.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_16.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44p51.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44u.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_8.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_11.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_16.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_22.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_32.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44p51.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44u.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_X.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/analysis.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/backends.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/bitrate.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/bitrate.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/block.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codebook.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codebook.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codec_internal.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/envelope.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/envelope.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/floor0.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/floor1.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/highlevel.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/info.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup_data.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lpc.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lpc.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lsp.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lsp.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mapping0.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/masking.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mdct.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mdct.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/misc.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/misc.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/os.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/psy.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/psy.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/registry.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/registry.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/res0.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/scales.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/sharedbook.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/smallft.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/smallft.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/synthesis.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/vorbisenc.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/vorbisfile.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/window.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/window.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/README.md"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/bitwise.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/codec.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/config_types.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/crctable.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/framing.c"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/Ogg Vorbis Licence.txt"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/ogg.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/os_types.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisenc.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisfile.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_MemoryMappedAudioFormatReader.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.h"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/juce_audio_formats.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/juce_audio_formats.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_formats/juce_audio_formats.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AAX/juce_AAX_Modifier_Injector.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AAX/juce_AAX_Wrapper.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBase.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBase.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBaseHelper.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBuffer.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBuffer.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewBase.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewBase.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewControl.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewControl.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewDispatch.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUDispatch.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUDispatch.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputElement.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputElement.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputFormatConverter.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUMIDIBase.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUMIDIBase.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputBase.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputBase.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputElement.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputElement.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUPlugInDispatch.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUPlugInDispatch.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUScopeElement.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUScopeElement.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUSilentTimeout.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUTimestampGenerator.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUViewLocalizedStringKeys.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAtomic.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAtomicStack.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAudioChannelLayout.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAudioChannelLayout.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAUParameter.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAUParameter.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAutoDisposer.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CADebugMacros.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CADebugPrintf.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAException.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAHostTimeBase.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMath.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMutex.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMutex.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CarbonEventHandler.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CarbonEventHandler.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAReferenceCounted.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAStreamBasicDescription.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAStreamBasicDescription.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAThreadSafeList.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnit.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnit.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnitTypes.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAXException.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/ComponentBase.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/ComponentBase.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/MusicDeviceBase.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/MusicDeviceBase.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/juce_AU_Wrapper.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/juce_AUv3_Wrapper.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/RTAS/juce_RTAS_DigiCode_Header.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/RTAS/juce_RTAS_DigiCode1.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/RTAS/juce_RTAS_DigiCode2.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/RTAS/juce_RTAS_DigiCode3.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/RTAS/juce_RTAS_MacUtilities.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/RTAS/juce_RTAS_WinUtilities.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/RTAS/juce_RTAS_Wrapper.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/Standalone/juce_StandaloneFilterApp.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/Standalone/juce_StandaloneFilterWindow.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/Unity/juce_Unity_Wrapper.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/Unity/juce_UnityPluginInterface.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_CarbonVisibility.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_CheckSettingMacros.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_CreatePluginFilter.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_FakeMouseMoveGenerator.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_IncludeModuleHeaders.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_IncludeSystemHeaders.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_LinuxMessageThread.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_PluginUtilities.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_WindowsHooks.h"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/VST3/juce_VST3_Wrapper.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_AAX.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_AAX.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_AU_1.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_AU_2.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_AUv3.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_RTAS_1.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_RTAS_2.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_RTAS_3.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_RTAS_4.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_RTAS_utils.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_RTAS_utils.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_Standalone.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_Unity.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_utils.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_VST_utils.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_VST2.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_VST3.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/baseiids.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/classfactoryhelpers.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fbuffer.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fbuffer.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fdebug.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fdebug.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fobject.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fobject.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstreamer.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstreamer.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstring.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstring.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/updatehandler.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/updatehandler.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/thread/include/flock.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/thread/source/flock.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/LICENSE.txt"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/README.md"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/conststringtable.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/conststringtable.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/coreiids.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/falignpop.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/falignpush.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fplatform.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fstrdefs.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ftypes.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/funknown.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/funknown.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/futils.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fvariant.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ibstream.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/icloneable.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ipersistent.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ipluginbase.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/istringresult.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/iupdatehandler.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/smartpointer.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/typesizecheck.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ustring.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ustring.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/gui/iplugview.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/gui/iplugviewcontentscalesupport.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstattributes.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstaudioprocessor.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstautomationstate.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstchannelcontextinfo.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstcomponent.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstcontextmenu.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsteditcontroller.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstevents.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsthostapplication.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstinterappaudio.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmessage.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmidicontrollers.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmidilearn.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstnoteexpression.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstparameterchanges.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstparameterfunctionname.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstphysicalui.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstpluginterfacesupport.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstplugview.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstprefetchablesupport.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstprocesscontext.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstrepresentation.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsttestplugprovider.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstunits.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vstpshpack4.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vstspeaker.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vsttypes.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/LICENSE.txt"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/README.md"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/memorystream.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/memorystream.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/pluginview.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/pluginview.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/hostclasses.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/hostclasses.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/pluginterfacesupport.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/pluginterfacesupport.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstbus.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstbus.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponent.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponentbase.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponentbase.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vsteditcontroller.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vsteditcontroller.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstinitiids.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstparameters.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstparameters.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstpresetfile.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstpresetfile.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/LICENSE.txt"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/README.md"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/JUCE_README.md"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/LICENSE.txt"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/README.md"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_AU_Shared.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_LegacyAudioParameter.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_VST3Common.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_VST3Headers.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_VSTCommon.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_VSTMidiEventList.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditorHostContext.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorListener.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameter.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameterGroup.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameterGroup.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterBool.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterBool.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterChoice.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterChoice.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterFloat.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterFloat.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterInt.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterInt.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_ExtensionsVisitor.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_ParameterAttachments.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_ParameterAttachments.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_PluginHostType.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_PluginHostType.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_RangedAudioParameter.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_RangedAudioParameter.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_VST3ClientExtensions.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_VSTCallbackHandler.h"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/juce_audio_processors.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/juce_audio_processors.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_processors/juce_audio_processors.h"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDBurner.h"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.h"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.h"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.h"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.h"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailBase.h"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.h"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.h"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_BluetoothMidiDevicePairingDialogue.h"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.h"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_android_BluetoothMidiDevicePairingDialogue.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_ios_BluetoothMidiDevicePairingDialogue.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_linux_AudioCDReader.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_linux_BluetoothMidiDevicePairingDialogue.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDBurner.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDReader.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_mac_BluetoothMidiDevicePairingDialogue.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_win_BluetoothMidiDevicePairingDialogue.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDBurner.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDReader.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.h"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.h"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/juce_audio_utils.cpp"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/juce_audio_utils.mm"
    "../../../../JUCE/JUCE/modules/juce_audio_utils/juce_audio_utils.h"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_AbstractFifo.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_AbstractFifo.h"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_Array.h"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_ArrayAllocationBase.h"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_ArrayBase.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_ArrayBase.h"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_DynamicObject.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_DynamicObject.h"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_ElementComparator.h"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_HashMap.h"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_HashMap_test.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_LinkedListPointer.h"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_ListenerList.h"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_NamedValueSet.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_NamedValueSet.h"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_OwnedArray.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_OwnedArray.h"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_PropertySet.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_PropertySet.h"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.h"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_ScopedValueSetter.h"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_SortedSet.h"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_SparseSet.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_SparseSet.h"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_Variant.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/containers/juce_Variant.h"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_DirectoryIterator.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_DirectoryIterator.h"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_File.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_File.h"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_FileFilter.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_FileFilter.h"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_FileInputStream.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_FileInputStream.h"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_FileOutputStream.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_FileOutputStream.h"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_FileSearchPath.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_FileSearchPath.h"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_MemoryMappedFile.h"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_RangedDirectoryIterator.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_RangedDirectoryIterator.h"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_TemporaryFile.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_TemporaryFile.h"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_WildcardFileFilter.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/files/juce_WildcardFileFilter.h"
    "../../../../JUCE/JUCE/modules/juce_core/javascript/juce_Javascript.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/javascript/juce_Javascript.h"
    "../../../../JUCE/JUCE/modules/juce_core/javascript/juce_JSON.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/javascript/juce_JSON.h"
    "../../../../JUCE/JUCE/modules/juce_core/logging/juce_FileLogger.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/logging/juce_FileLogger.h"
    "../../../../JUCE/JUCE/modules/juce_core/logging/juce_Logger.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/logging/juce_Logger.h"
    "../../../../JUCE/JUCE/modules/juce_core/maths/juce_BigInteger.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/maths/juce_BigInteger.h"
    "../../../../JUCE/JUCE/modules/juce_core/maths/juce_Expression.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/maths/juce_Expression.h"
    "../../../../JUCE/JUCE/modules/juce_core/maths/juce_MathsFunctions.h"
    "../../../../JUCE/JUCE/modules/juce_core/maths/juce_NormalisableRange.h"
    "../../../../JUCE/JUCE/modules/juce_core/maths/juce_Random.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/maths/juce_Random.h"
    "../../../../JUCE/JUCE/modules/juce_core/maths/juce_Range.h"
    "../../../../JUCE/JUCE/modules/juce_core/maths/juce_StatisticsAccumulator.h"
    "../../../../JUCE/JUCE/modules/juce_core/memory/juce_AllocationHooks.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/memory/juce_AllocationHooks.h"
    "../../../../JUCE/JUCE/modules/juce_core/memory/juce_Atomic.h"
    "../../../../JUCE/JUCE/modules/juce_core/memory/juce_ByteOrder.h"
    "../../../../JUCE/JUCE/modules/juce_core/memory/juce_ContainerDeletePolicy.h"
    "../../../../JUCE/JUCE/modules/juce_core/memory/juce_HeapBlock.h"
    "../../../../JUCE/JUCE/modules/juce_core/memory/juce_HeavyweightLeakedObjectDetector.h"
    "../../../../JUCE/JUCE/modules/juce_core/memory/juce_LeakedObjectDetector.h"
    "../../../../JUCE/JUCE/modules/juce_core/memory/juce_Memory.h"
    "../../../../JUCE/JUCE/modules/juce_core/memory/juce_MemoryBlock.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/memory/juce_MemoryBlock.h"
    "../../../../JUCE/JUCE/modules/juce_core/memory/juce_OptionalScopedPointer.h"
    "../../../../JUCE/JUCE/modules/juce_core/memory/juce_ReferenceCountedObject.h"
    "../../../../JUCE/JUCE/modules/juce_core/memory/juce_ScopedPointer.h"
    "../../../../JUCE/JUCE/modules/juce_core/memory/juce_SharedResourcePointer.h"
    "../../../../JUCE/JUCE/modules/juce_core/memory/juce_Singleton.h"
    "../../../../JUCE/JUCE/modules/juce_core/memory/juce_WeakReference.h"
    "../../../../JUCE/JUCE/modules/juce_core/misc/juce_ConsoleApplication.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/misc/juce_ConsoleApplication.h"
    "../../../../JUCE/JUCE/modules/juce_core/misc/juce_Functional.h"
    "../../../../JUCE/JUCE/modules/juce_core/misc/juce_Result.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/misc/juce_Result.h"
    "../../../../JUCE/JUCE/modules/juce_core/misc/juce_RuntimePermissions.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/misc/juce_RuntimePermissions.h"
    "../../../../JUCE/JUCE/modules/juce_core/misc/juce_Uuid.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/misc/juce_Uuid.h"
    "../../../../JUCE/JUCE/modules/juce_core/misc/juce_WindowsRegistry.h"
    "../../../../JUCE/JUCE/modules/juce_core/native/java/README.txt"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_android_Files.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_android_JNIHelpers.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_android_JNIHelpers.h"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_android_Misc.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_android_Network.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_android_RuntimePermissions.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_android_SystemStats.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_android_Threads.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_BasicNativeHeaders.h"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_curl_Network.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_intel_SharedCode.h"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_linux_CommonFile.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_linux_Files.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_linux_Network.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_linux_SystemStats.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_linux_Threads.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_mac_CFHelpers.h"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_mac_Files.mm"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_mac_Network.mm"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_mac_ObjCHelpers.h"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_mac_Strings.mm"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_mac_SystemStats.mm"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_mac_Threads.mm"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_posix_IPAddress.h"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_posix_NamedPipe.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_posix_SharedCode.h"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_wasm_SystemStats.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_win32_ComSmartPtr.h"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_win32_Files.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_win32_Network.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_win32_Registry.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_win32_SystemStats.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/native/juce_win32_Threads.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/network/juce_IPAddress.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/network/juce_IPAddress.h"
    "../../../../JUCE/JUCE/modules/juce_core/network/juce_MACAddress.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/network/juce_MACAddress.h"
    "../../../../JUCE/JUCE/modules/juce_core/network/juce_NamedPipe.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/network/juce_NamedPipe.h"
    "../../../../JUCE/JUCE/modules/juce_core/network/juce_Socket.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/network/juce_Socket.h"
    "../../../../JUCE/JUCE/modules/juce_core/network/juce_URL.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/network/juce_URL.h"
    "../../../../JUCE/JUCE/modules/juce_core/network/juce_WebInputStream.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/network/juce_WebInputStream.h"
    "../../../../JUCE/JUCE/modules/juce_core/streams/juce_BufferedInputStream.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/streams/juce_BufferedInputStream.h"
    "../../../../JUCE/JUCE/modules/juce_core/streams/juce_FileInputSource.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/streams/juce_FileInputSource.h"
    "../../../../JUCE/JUCE/modules/juce_core/streams/juce_InputSource.h"
    "../../../../JUCE/JUCE/modules/juce_core/streams/juce_InputStream.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/streams/juce_InputStream.h"
    "../../../../JUCE/JUCE/modules/juce_core/streams/juce_MemoryInputStream.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/streams/juce_MemoryInputStream.h"
    "../../../../JUCE/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.h"
    "../../../../JUCE/JUCE/modules/juce_core/streams/juce_OutputStream.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/streams/juce_OutputStream.h"
    "../../../../JUCE/JUCE/modules/juce_core/streams/juce_SubregionStream.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/streams/juce_SubregionStream.h"
    "../../../../JUCE/JUCE/modules/juce_core/streams/juce_URLInputSource.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/streams/juce_URLInputSource.h"
    "../../../../JUCE/JUCE/modules/juce_core/system/juce_CompilerSupport.h"
    "../../../../JUCE/JUCE/modules/juce_core/system/juce_CompilerWarnings.h"
    "../../../../JUCE/JUCE/modules/juce_core/system/juce_PlatformDefs.h"
    "../../../../JUCE/JUCE/modules/juce_core/system/juce_StandardHeader.h"
    "../../../../JUCE/JUCE/modules/juce_core/system/juce_SystemStats.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/system/juce_SystemStats.h"
    "../../../../JUCE/JUCE/modules/juce_core/system/juce_TargetPlatform.h"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_Base64.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_Base64.h"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_CharacterFunctions.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_CharacterFunctions.h"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_CharPointer_ASCII.h"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_CharPointer_UTF8.h"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_CharPointer_UTF16.h"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_CharPointer_UTF32.h"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_Identifier.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_Identifier.h"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_LocalisedStrings.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_LocalisedStrings.h"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_NewLine.h"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_String.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_String.h"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_StringArray.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_StringArray.h"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_StringPairArray.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_StringPairArray.h"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_StringPool.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_StringPool.h"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_StringRef.h"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_TextDiff.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/text/juce_TextDiff.h"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_ChildProcess.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_ChildProcess.h"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_CriticalSection.h"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_DynamicLibrary.h"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.h"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_InterProcessLock.h"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_Process.h"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_ReadWriteLock.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_ReadWriteLock.h"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_ScopedLock.h"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_ScopedReadLock.h"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_ScopedWriteLock.h"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_SpinLock.h"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_Thread.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_Thread.h"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_ThreadLocalValue.h"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_ThreadPool.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_ThreadPool.h"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_TimeSliceThread.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_TimeSliceThread.h"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_WaitableEvent.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/threads/juce_WaitableEvent.h"
    "../../../../JUCE/JUCE/modules/juce_core/time/juce_PerformanceCounter.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/time/juce_PerformanceCounter.h"
    "../../../../JUCE/JUCE/modules/juce_core/time/juce_RelativeTime.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/time/juce_RelativeTime.h"
    "../../../../JUCE/JUCE/modules/juce_core/time/juce_Time.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/time/juce_Time.h"
    "../../../../JUCE/JUCE/modules/juce_core/unit_tests/juce_UnitTest.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/unit_tests/juce_UnitTest.h"
    "../../../../JUCE/JUCE/modules/juce_core/unit_tests/juce_UnitTestCategories.h"
    "../../../../JUCE/JUCE/modules/juce_core/xml/juce_XmlDocument.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/xml/juce_XmlDocument.h"
    "../../../../JUCE/JUCE/modules/juce_core/xml/juce_XmlElement.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/xml/juce_XmlElement.h"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/adler32.c"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/compress.c"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/crc32.c"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/crc32.h"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/deflate.c"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/deflate.h"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/infback.c"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/inffast.c"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/inffast.h"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/inffixed.h"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/inflate.c"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/inflate.h"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/inftrees.c"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/inftrees.h"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/trees.c"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/trees.h"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/uncompr.c"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/zconf.h"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/zconf.in.h"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/zlib.h"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/zutil.c"
    "../../../../JUCE/JUCE/modules/juce_core/zip/zlib/zutil.h"
    "../../../../JUCE/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.h"
    "../../../../JUCE/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.h"
    "../../../../JUCE/JUCE/modules/juce_core/zip/juce_ZipFile.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/zip/juce_ZipFile.h"
    "../../../../JUCE/JUCE/modules/juce_core/juce_core.cpp"
    "../../../../JUCE/JUCE/modules/juce_core/juce_core.mm"
    "../../../../JUCE/JUCE/modules/juce_core/juce_core.h"
    "../../../../JUCE/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.cpp"
    "../../../../JUCE/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.h"
    "../../../../JUCE/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.cpp"
    "../../../../JUCE/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.h"
    "../../../../JUCE/JUCE/modules/juce_data_structures/undomanager/juce_UndoableAction.h"
    "../../../../JUCE/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.cpp"
    "../../../../JUCE/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.h"
    "../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_CachedValue.cpp"
    "../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_CachedValue.h"
    "../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_Value.cpp"
    "../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_Value.h"
    "../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_ValueTree.cpp"
    "../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_ValueTree.h"
    "../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.cpp"
    "../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.h"
    "../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.cpp"
    "../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.h"
    "../../../../JUCE/JUCE/modules/juce_data_structures/juce_data_structures.cpp"
    "../../../../JUCE/JUCE/modules/juce_data_structures/juce_data_structures.mm"
    "../../../../JUCE/JUCE/modules/juce_data_structures/juce_data_structures.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/containers/juce_AudioBlock.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/containers/juce_AudioBlock_test.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/containers/juce_FixedSizeFunction.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/containers/juce_FixedSizeFunction_test.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/containers/juce_SIMDRegister.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/containers/juce_SIMDRegister_Impl.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/containers/juce_SIMDRegister_test.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/filter_design/juce_FilterDesign.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/filter_design/juce_FilterDesign.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/frequency/juce_Convolution.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/frequency/juce_Convolution.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/frequency/juce_Convolution_test.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/frequency/juce_FFT.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/frequency/juce_FFT.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/frequency/juce_FFT_test.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/frequency/juce_Windowing.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/frequency/juce_Windowing.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_FastMathApproximations.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_LogRampedValue.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_LogRampedValue_test.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_LookupTable.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_LookupTable.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_Matrix.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_Matrix.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_Matrix_test.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_Phase.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_Polynomial.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_SpecialFunctions.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_SpecialFunctions.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/native/juce_avx_SIMDNativeOps.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/native/juce_avx_SIMDNativeOps.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/native/juce_fallback_SIMDNativeOps.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/native/juce_neon_SIMDNativeOps.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/native/juce_neon_SIMDNativeOps.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/native/juce_sse_SIMDNativeOps.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/native/juce_sse_SIMDNativeOps.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_BallisticsFilter.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_BallisticsFilter.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_DelayLine.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_DelayLine.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_DryWetMixer.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_DryWetMixer.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_FIRFilter.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_FIRFilter.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_FIRFilter_test.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_FirstOrderTPTFilter.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_FirstOrderTPTFilter.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_IIRFilter.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_IIRFilter.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_IIRFilter_Impl.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_LinkwitzRileyFilter.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_LinkwitzRileyFilter.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_Oversampling.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_Oversampling.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_Panner.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_Panner.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_ProcessContext.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_ProcessorChain.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_ProcessorChain_test.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_ProcessorDuplicator.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_ProcessorWrapper.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_StateVariableFilter.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_StateVariableTPTFilter.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_StateVariableTPTFilter.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Bias.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Chorus.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Chorus.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Compressor.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Compressor.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Gain.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_LadderFilter.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_LadderFilter.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Limiter.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Limiter.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_NoiseGate.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_NoiseGate.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Oscillator.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Phaser.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Phaser.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Reverb.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_WaveShaper.h"
    "../../../../JUCE/JUCE/modules/juce_dsp/juce_dsp.cpp"
    "../../../../JUCE/JUCE/modules/juce_dsp/juce_dsp.mm"
    "../../../../JUCE/JUCE/modules/juce_dsp/juce_dsp.h"
    "../../../../JUCE/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.h"
    "../../../../JUCE/JUCE/modules/juce_events/broadcasters/juce_ActionListener.h"
    "../../../../JUCE/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.h"
    "../../../../JUCE/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.h"
    "../../../../JUCE/JUCE/modules/juce_events/broadcasters/juce_ChangeListener.h"
    "../../../../JUCE/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.h"
    "../../../../JUCE/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.h"
    "../../../../JUCE/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.h"
    "../../../../JUCE/JUCE/modules/juce_events/interprocess/juce_NetworkServiceDiscovery.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/interprocess/juce_NetworkServiceDiscovery.h"
    "../../../../JUCE/JUCE/modules/juce_events/messages/juce_ApplicationBase.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/messages/juce_ApplicationBase.h"
    "../../../../JUCE/JUCE/modules/juce_events/messages/juce_CallbackMessage.h"
    "../../../../JUCE/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.h"
    "../../../../JUCE/JUCE/modules/juce_events/messages/juce_Initialisation.h"
    "../../../../JUCE/JUCE/modules/juce_events/messages/juce_Message.h"
    "../../../../JUCE/JUCE/modules/juce_events/messages/juce_MessageListener.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/messages/juce_MessageListener.h"
    "../../../../JUCE/JUCE/modules/juce_events/messages/juce_MessageManager.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/messages/juce_MessageManager.h"
    "../../../../JUCE/JUCE/modules/juce_events/messages/juce_MountedVolumeListChangeDetector.h"
    "../../../../JUCE/JUCE/modules/juce_events/messages/juce_NotificationType.h"
    "../../../../JUCE/JUCE/modules/juce_events/native/juce_android_Messaging.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/native/juce_ios_MessageManager.mm"
    "../../../../JUCE/JUCE/modules/juce_events/native/juce_linux_EventLoop.h"
    "../../../../JUCE/JUCE/modules/juce_events/native/juce_linux_Messaging.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/native/juce_mac_MessageManager.mm"
    "../../../../JUCE/JUCE/modules/juce_events/native/juce_osx_MessageQueue.h"
    "../../../../JUCE/JUCE/modules/juce_events/native/juce_ScopedLowPowerModeDisabler.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/native/juce_ScopedLowPowerModeDisabler.h"
    "../../../../JUCE/JUCE/modules/juce_events/native/juce_win32_HiddenMessageWindow.h"
    "../../../../JUCE/JUCE/modules/juce_events/native/juce_win32_Messaging.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.h"
    "../../../../JUCE/JUCE/modules/juce_events/timers/juce_MultiTimer.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/timers/juce_MultiTimer.h"
    "../../../../JUCE/JUCE/modules/juce_events/timers/juce_Timer.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/timers/juce_Timer.h"
    "../../../../JUCE/JUCE/modules/juce_events/juce_events.cpp"
    "../../../../JUCE/JUCE/modules/juce_events/juce_events.mm"
    "../../../../JUCE/JUCE/modules/juce_events/juce_events.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_Colour.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_Colour.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_ColourGradient.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_ColourGradient.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_Colours.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_Colours.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_FillType.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_FillType.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_PixelFormats.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsContext.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/effects/juce_GlowEffect.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/effects/juce_GlowEffect.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/effects/juce_ImageEffectFilter.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_AttributedString.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_AttributedString.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_Font.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_Font.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_TextLayout.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_TextLayout.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_Typeface.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_Typeface.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_BorderSize.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_Line.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_Parallelogram.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_Path.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_Path.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_PathIterator.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_PathIterator.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_Point.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_Rectangle.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_RectangleList.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/cderror.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/changes to libjpeg for JUCE.txt"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcapimin.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcapistd.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jccoefct.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jccolor.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcdctmgr.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcinit.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcmainct.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcmarker.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcmaster.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcomapi.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jconfig.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcparam.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcphuff.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcprepct.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcsample.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jctrans.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdapimin.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdapistd.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdatasrc.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdcoefct.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdcolor.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdct.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jddctmgr.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdinput.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdmainct.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdmarker.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdmaster.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdmerge.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdphuff.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdpostct.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdsample.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdtrans.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctflt.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctfst.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctint.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jidctflt.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jidctfst.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jidctint.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jidctred.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jinclude.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jmemmgr.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jmemnobs.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jmemsys.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jmorecfg.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jpegint.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jpeglib.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jquant1.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jquant2.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jutils.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jversion.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/libpng_readme.txt"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/png.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/png.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngconf.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngdebug.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngerror.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngget.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pnginfo.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngmem.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngpread.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngpriv.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngread.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngrio.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngrtran.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngrutil.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngset.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngstruct.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngtrans.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngwio.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngwrite.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngwtran.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngwutil.c"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/juce_GIFLoader.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/juce_JPEGLoader.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/image_formats/juce_PNGLoader.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/images/juce_Image.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/images/juce_Image.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/images/juce_ImageCache.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/images/juce_ImageCache.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_android_Fonts.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_android_GraphicsContext.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_android_IconHelpers.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_freetype_Fonts.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_linux_Fonts.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_linux_IconHelpers.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.mm"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsHelpers.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_mac_Fonts.mm"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_mac_IconHelpers.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_RenderingHelpers.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeface.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeLayout.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_win32_Fonts.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/native/juce_win32_IconHelpers.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/placement/juce_Justification.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.h"
    "../../../../JUCE/JUCE/modules/juce_graphics/juce_graphics.cpp"
    "../../../../JUCE/JUCE/modules/juce_graphics/juce_graphics.mm"
    "../../../../JUCE/JUCE/modules/juce_graphics/juce_graphics.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/enums/juce_AccessibilityActions.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/enums/juce_AccessibilityEvent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/enums/juce_AccessibilityRole.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/interfaces/juce_AccessibilityCellInterface.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/interfaces/juce_AccessibilityTableInterface.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/interfaces/juce_AccessibilityTextInterface.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/interfaces/juce_AccessibilityValueInterface.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/juce_AccessibilityHandler.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/juce_AccessibilityHandler.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/juce_AccessibilityState.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/application/juce_Application.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/application/juce_Application.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_Button.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_Button.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandID.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_CachedComponentImage.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_Component.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_Component.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_ComponentTraverser.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_FocusTraverser.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_FocusTraverser.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/desktop/juce_Desktop.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/desktop/juce_Desktop.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/desktop/juce_Displays.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/desktop/juce_Displays.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_SVGParser.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserListener.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FilePreviewComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_SystemClipboard.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_TextEditorKeyMapper.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_TextInputTarget.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPosition.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPositionBehaviours.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_FlexItem.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_Grid.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_Grid.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_GridItem.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_GridItem.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_Viewport.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_Viewport.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropTarget.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_FileDragAndDropTarget.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_LassoComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_SelectedItemSet.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_TextDragAndDropTarget.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_TooltipClient.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_AccessibilityTextHelpers.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_android_Accessibility.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_ios_Accessibility.mm"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_mac_Accessibility.mm"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_mac_AccessibilitySharedCode.mm"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_Accessibility.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_AccessibilityElement.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_AccessibilityElement.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAExpandCollapseProvider.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAGridItemProvider.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAGridProvider.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAHelpers.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAInvokeProvider.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAProviderBase.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAProviders.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIARangeValueProvider.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIASelectionProvider.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIATextProvider.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAToggleProvider.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIATransformProvider.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAValueProvider.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAWindowProvider.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_WindowsUIAWrapper.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/x11/juce_linux_X11_DragAndDrop.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/x11/juce_linux_X11_Symbols.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/x11/juce_linux_X11_Symbols.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/x11/juce_linux_XWindowSystem.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/x11/juce_linux_XWindowSystem.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_android_ContentSharer.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_android_FileChooser.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_android_Windowing.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_common_MimeTypes.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_ios_ContentSharer.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_ios_FileChooser.mm"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_ios_UIViewComponentPeer.mm"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_ios_Windowing.mm"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_linux_FileChooser.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_linux_Windowing.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_mac_FileChooser.mm"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_mac_MainMenu.mm"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_mac_MouseCursor.mm"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_mac_NSViewComponentPeer.mm"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_mac_Windowing.mm"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_MultiTouchMapper.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_win32_DragAndDrop.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_win32_FileChooser.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_win32_ScopedThreadDPIAwarenessSetter.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_win32_Windowing.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_Label.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_Label.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_Slider.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_Slider.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemFactory.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_MessageBoxOptions.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_NativeMessageBox.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.h"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/juce_gui_basics.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/juce_gui_basics.mm"
    "../../../../JUCE/JUCE/modules/juce_gui_basics/juce_gui_basics.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_CodeTokeniser.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniserFunctions.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/embedding/juce_ActiveXControlComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/embedding/juce_AndroidViewComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/embedding/juce_HWNDComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/embedding/juce_NSViewComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/embedding/juce_ScopedDPIAwarenessDisabler.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/embedding/juce_UIViewComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/embedding/juce_XEmbedComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_AppleRemote.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_WebBrowserComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_android_PushNotifications.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_android_WebBrowserComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_AndroidViewComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_ios_PushNotifications.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_ios_UIViewComponent.mm"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_linux_X11_SystemTrayIcon.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_linux_X11_WebBrowserComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_linux_XEmbedComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_mac_AppleRemote.mm"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_mac_CarbonViewWrapperComponent.h"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_mac_NSViewComponent.mm"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_mac_PushNotifications.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_mac_SystemTrayIcon.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_mac_WebBrowserComponent.mm"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_win32_ActiveXComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_win32_HWNDComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_win32_SystemTrayIcon.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_win32_WebBrowserComponent.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/juce_gui_extra.cpp"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/juce_gui_extra.mm"
    "../../../../JUCE/JUCE/modules/juce_gui_extra/juce_gui_extra.h"
    "../../../JuceLibraryCode/BinaryData.cpp"
    "../../../JuceLibraryCode/BinaryData.h"
    "../../../JuceLibraryCode/include_juce_audio_basics.cpp"
    "../../../JuceLibraryCode/include_juce_audio_devices.cpp"
    "../../../JuceLibraryCode/include_juce_audio_formats.cpp"
    "../../../JuceLibraryCode/include_juce_audio_plugin_client_utils.cpp"
    "../../../JuceLibraryCode/include_juce_audio_processors.cpp"
    "../../../JuceLibraryCode/include_juce_audio_utils.cpp"
    "../../../JuceLibraryCode/include_juce_core.cpp"
    "../../../JuceLibraryCode/include_juce_data_structures.cpp"
    "../../../JuceLibraryCode/include_juce_dsp.cpp"
    "../../../JuceLibraryCode/include_juce_events.cpp"
    "../../../JuceLibraryCode/include_juce_graphics.cpp"
    "../../../JuceLibraryCode/include_juce_gui_basics.cpp"
    "../../../JuceLibraryCode/include_juce_gui_extra.cpp"
    "../../../JuceLibraryCode/JuceHeader.h"
    "../../../JuceLibraryCode/JucePluginDefines.h"
)

set_source_files_properties("../../../Source/PlasmaLabel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/CustomTextButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/CustomLabel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/LoudnessMeterComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/ResponseCurveComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/CustomRotarySlider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/CustomLookAndFeel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/PluginProcessor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/PluginEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Sedgwick_Ave_Display/OFL.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Sedgwick_Ave_Display/SedgwickAveDisplay-Regular.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Sedgwick_Ave/OFL.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Sedgwick_Ave/SedgwickAve-Regular.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/OFL.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-Black.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-BlackItalic.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-Bold.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-BoldItalic.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-ExtraBold.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-ExtraBoldItalic.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-ExtraLight.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-ExtraLightItalic.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-Italic.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-Light.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-LightItalic.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-Medium.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-MediumItalic.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-Regular.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-SemiBold.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-SemiBoldItalic.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-Thin.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Resources/Poppins/Poppins-ThinItalic.ttf" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/audio_play_head/juce_AudioPlayHead.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_AudioProcessLoadMeasurer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_AudioProcessLoadMeasurer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_AudioSampleBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMP.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPacket.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPackets.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPConversion.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPConverters.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPDispatcher.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPFactory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPMidi1ToBytestreamTranslator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPMidi1ToMidi2DefaultTranslator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPMidi1ToMidi2DefaultTranslator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPProtocols.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPReceiver.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPSysEx7.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPSysEx7.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPTests.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPUtils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPUtils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPView.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/ump/juce_UMPView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiDataConcatenator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/native/juce_mac_CoreAudioLayouts.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_AudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_PositionableAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_ADSR.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_ADSR_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_Decibels.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_GenericInterpolator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_IIRFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_IIRFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_Interpolators.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_Interpolators.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_LagrangeInterpolator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_Reverb.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_SmoothedValue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_SmoothedValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/utilities/juce_WindowedSincInterpolator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/juce_audio_basics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/juce_audio_basics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_basics/juce_audio_basics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/audio_io/juce_SystemAudioVolume.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPBytestreamInputHandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPTests.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPU32InputHandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/midi_io/juce_MidiDevices.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/midi_io/juce_MidiDevices.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/AudioStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/AudioStreamBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/AudioStreamBuilder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/AudioStreamCallback.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/Definitions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/LatencyTuner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/Oboe.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/ResultWithValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/StabilizedCallback.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/Utilities.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/Version.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AAudioExtensions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AAudioLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AAudioLoader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AudioStreamAAudio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AudioStreamAAudio.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioClock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioSourceCaller.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioSourceCaller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioStreamBuilder.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/DataConversionFlowGraph.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/DataConversionFlowGraph.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/FilterAudioStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/FilterAudioStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockAdapter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockAdapter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockWriter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockWriter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/LatencyTuner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/MonotonicCounter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/OboeDebug.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/QuirksManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/QuirksManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceFloatCaller.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceFloatCaller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceI16Caller.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceI16Caller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceI24Caller.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceI24Caller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceI32Caller.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceI32Caller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/StabilizedCallback.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/Trace.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/Trace.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/Utilities.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/common/Version.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoBuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoController.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoController.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoControllerBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoControllerBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoControllerIndirect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoControllerIndirect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/HyperbolicCosineWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/IntegerRatio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/IntegerRatio.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/KaiserWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/LinearResampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/LinearResampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/MultiChannelResampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/MultiChannelResampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerMono.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerMono.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerStereo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerStereo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResamplerStereo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResamplerStereo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ChannelCountConverter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ChannelCountConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ClipToRange.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ClipToRange.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/FlowGraphNode.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/FlowGraphNode.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/FlowgraphUtilities.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ManyToMultiConverter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ManyToMultiConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/MonoToMultiConverter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/MonoToMultiConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/MultiToMonoConverter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/MultiToMonoConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/RampLinear.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/RampLinear.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SampleRateConverter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SampleRateConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkFloat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkFloat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI16.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI24.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI24.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI32.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceFloat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceFloat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI16.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI24.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI24.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI32.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioInputStreamOpenSLES.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioInputStreamOpenSLES.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioOutputStreamOpenSLES.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioOutputStreamOpenSLES.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioStreamBuffered.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioStreamBuffered.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioStreamOpenSLES.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioStreamOpenSLES.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/EngineOpenSLES.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/EngineOpenSLES.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/OpenSLESUtilities.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/OpenSLESUtilities.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/OutputMixerOpenSLES.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/OutputMixerOpenSLES.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/CMakeLists.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/oboe/README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_android_Audio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_android_HighPerformanceAudioHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_android_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_android_Oboe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_android_OpenSL.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_linux_ALSA.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_linux_Bela.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_linux_JackAudio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_linux_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_mac_CoreAudio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_mac_CoreMidi.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_win32_ASIO.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_win32_DirectSound.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_win32_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/native/juce_win32_WASAPI.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/juce_audio_devices.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/juce_audio_devices.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_devices/juce_audio_devices.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitmath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitreader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitwriter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/cpu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/crc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/fixed.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/float.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/format.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/lpc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/md5.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/memory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/metadata.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder_framing.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/window.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_decoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitmath.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitreader.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitwriter.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/cpu.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/crc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/fixed.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/float.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/format.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/lpc_flac.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/md5.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/memory.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_decoder.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder_framing.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/window_flac.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/alloc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/assert.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/callback.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/compat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/endswap.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/export.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/Flac Licence.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/format.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/metadata.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/ordinals.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/stream_decoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/flac/win_utf8_io.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/coupled/res_books_51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/coupled/res_books_stereo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/floor/floor_books.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/uncoupled/res_books_uncoupled.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/floor_all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44p51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44u.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_22.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44p51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44u.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_X.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/analysis.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/backends.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/bitrate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/bitrate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/block.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codebook.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codebook.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codec_internal.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/envelope.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/envelope.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/floor0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/floor1.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/highlevel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/info.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup_data.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lpc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lpc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lsp.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lsp.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mapping0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/masking.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mdct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mdct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/misc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/misc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/os.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/psy.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/psy.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/registry.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/registry.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/res0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/scales.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/sharedbook.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/smallft.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/smallft.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/synthesis.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/vorbisenc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/vorbisfile.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/window.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/window.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/bitwise.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/codec.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/config_types.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/crctable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/framing.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/Ogg Vorbis Licence.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/ogg.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/os_types.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisenc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisfile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/format/juce_MemoryMappedAudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/juce_audio_formats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/juce_audio_formats.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_formats/juce_audio_formats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AAX/juce_AAX_Modifier_Injector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AAX/juce_AAX_Wrapper.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBaseHelper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewControl.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewControl.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewDispatch.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUDispatch.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUDispatch.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputFormatConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUMIDIBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUMIDIBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUPlugInDispatch.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUPlugInDispatch.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUScopeElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUScopeElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUSilentTimeout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUTimestampGenerator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUViewLocalizedStringKeys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAtomic.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAtomicStack.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAudioChannelLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAudioChannelLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAUParameter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAUParameter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAutoDisposer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CADebugMacros.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CADebugPrintf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAException.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAHostTimeBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMutex.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMutex.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CarbonEventHandler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CarbonEventHandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAReferenceCounted.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAStreamBasicDescription.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAStreamBasicDescription.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAThreadSafeList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnit.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnit.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnitTypes.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAXException.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/ComponentBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/ComponentBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/MusicDeviceBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/MusicDeviceBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/juce_AU_Wrapper.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/AU/juce_AUv3_Wrapper.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/RTAS/juce_RTAS_DigiCode_Header.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/RTAS/juce_RTAS_DigiCode1.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/RTAS/juce_RTAS_DigiCode2.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/RTAS/juce_RTAS_DigiCode3.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/RTAS/juce_RTAS_MacUtilities.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/RTAS/juce_RTAS_WinUtilities.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/RTAS/juce_RTAS_Wrapper.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/Standalone/juce_StandaloneFilterApp.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/Standalone/juce_StandaloneFilterWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/Unity/juce_Unity_Wrapper.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/Unity/juce_UnityPluginInterface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_CarbonVisibility.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_CheckSettingMacros.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_CreatePluginFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_FakeMouseMoveGenerator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_IncludeModuleHeaders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_IncludeSystemHeaders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_LinuxMessageThread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_PluginUtilities.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/utility/juce_WindowsHooks.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/VST3/juce_VST3_Wrapper.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_AAX.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_AAX.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_AU_1.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_AU_2.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_AUv3.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_RTAS_1.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_RTAS_2.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_RTAS_3.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_RTAS_4.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_RTAS_utils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_RTAS_utils.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_Standalone.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_Unity.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_utils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_VST_utils.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_VST2.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_VST3.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/baseiids.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/classfactoryhelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fbuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fbuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fdebug.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fdebug.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fobject.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fobject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstreamer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstreamer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstring.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstring.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/updatehandler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/updatehandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/thread/include/flock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/thread/source/flock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/LICENSE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/conststringtable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/conststringtable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/coreiids.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/falignpop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/falignpush.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fplatform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fstrdefs.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ftypes.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/funknown.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/funknown.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/futils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fvariant.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ibstream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/icloneable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ipersistent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ipluginbase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/istringresult.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/iupdatehandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/smartpointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/typesizecheck.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ustring.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ustring.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/gui/iplugview.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/gui/iplugviewcontentscalesupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstattributes.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstaudioprocessor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstautomationstate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstchannelcontextinfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstcomponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstcontextmenu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsteditcontroller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstevents.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsthostapplication.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstinterappaudio.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmessage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmidicontrollers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmidilearn.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstnoteexpression.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstparameterchanges.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstparameterfunctionname.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstphysicalui.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstpluginterfacesupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstplugview.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstprefetchablesupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstprocesscontext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstrepresentation.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsttestplugprovider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstunits.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vstpshpack4.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vstspeaker.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vsttypes.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/LICENSE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/memorystream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/memorystream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/pluginview.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/pluginview.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/hostclasses.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/hostclasses.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/pluginterfacesupport.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/pluginterfacesupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstbus.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstbus.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponentbase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponentbase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vsteditcontroller.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vsteditcontroller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstinitiids.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstparameters.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstparameters.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstpresetfile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstpresetfile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/LICENSE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/JUCE_README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/LICENSE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_AU_Shared.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_LegacyAudioParameter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_VST3Common.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_VST3Headers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_VSTCommon.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_VSTMidiEventList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditorHostContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameterGroup.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameterGroup.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterBool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterBool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterChoice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterChoice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterFloat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterFloat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterInt.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterInt.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_ExtensionsVisitor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_ParameterAttachments.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_ParameterAttachments.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_PluginHostType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_PluginHostType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_RangedAudioParameter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_RangedAudioParameter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_VST3ClientExtensions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/utilities/juce_VSTCallbackHandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/juce_audio_processors.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/juce_audio_processors.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_processors/juce_audio_processors.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDBurner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_BluetoothMidiDevicePairingDialogue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_android_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_ios_BluetoothMidiDevicePairingDialogue.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_linux_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_linux_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDBurner.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDReader.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_mac_BluetoothMidiDevicePairingDialogue.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_win_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDBurner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/juce_audio_utils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/juce_audio_utils.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_audio_utils/juce_audio_utils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_AbstractFifo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_AbstractFifo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_Array.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_ArrayAllocationBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_ArrayBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_ArrayBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_DynamicObject.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_DynamicObject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_ElementComparator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_HashMap.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_HashMap_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_LinkedListPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_ListenerList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_NamedValueSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_NamedValueSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_OwnedArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_OwnedArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_PropertySet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_PropertySet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_ScopedValueSetter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_SortedSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_SparseSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_SparseSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_Variant.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/containers/juce_Variant.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_DirectoryIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_DirectoryIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_File.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_File.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_FileFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_FileFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_FileInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_FileInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_FileOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_FileOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_FileSearchPath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_FileSearchPath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_MemoryMappedFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_RangedDirectoryIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_RangedDirectoryIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_TemporaryFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_TemporaryFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_WildcardFileFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/files/juce_WildcardFileFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/javascript/juce_Javascript.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/javascript/juce_Javascript.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/javascript/juce_JSON.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/javascript/juce_JSON.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/logging/juce_FileLogger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/logging/juce_FileLogger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/logging/juce_Logger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/logging/juce_Logger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/maths/juce_BigInteger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/maths/juce_BigInteger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/maths/juce_Expression.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/maths/juce_Expression.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/maths/juce_MathsFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/maths/juce_NormalisableRange.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/maths/juce_Random.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/maths/juce_Random.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/maths/juce_Range.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/maths/juce_StatisticsAccumulator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/memory/juce_AllocationHooks.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/memory/juce_AllocationHooks.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/memory/juce_Atomic.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/memory/juce_ByteOrder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/memory/juce_ContainerDeletePolicy.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/memory/juce_HeapBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/memory/juce_HeavyweightLeakedObjectDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/memory/juce_LeakedObjectDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/memory/juce_Memory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/memory/juce_MemoryBlock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/memory/juce_MemoryBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/memory/juce_OptionalScopedPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/memory/juce_ReferenceCountedObject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/memory/juce_ScopedPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/memory/juce_SharedResourcePointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/memory/juce_Singleton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/memory/juce_WeakReference.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/misc/juce_ConsoleApplication.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/misc/juce_ConsoleApplication.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/misc/juce_Functional.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/misc/juce_Result.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/misc/juce_Result.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/misc/juce_RuntimePermissions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/misc/juce_RuntimePermissions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/misc/juce_Uuid.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/misc/juce_Uuid.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/misc/juce_WindowsRegistry.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/java/README.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_android_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_android_JNIHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_android_JNIHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_android_Misc.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_android_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_android_RuntimePermissions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_android_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_android_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_BasicNativeHeaders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_curl_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_intel_SharedCode.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_linux_CommonFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_linux_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_linux_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_linux_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_linux_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_mac_CFHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_mac_Files.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_mac_Network.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_mac_ObjCHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_mac_Strings.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_mac_SystemStats.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_mac_Threads.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_posix_IPAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_posix_NamedPipe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_posix_SharedCode.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_wasm_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_win32_ComSmartPtr.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_win32_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_win32_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_win32_Registry.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_win32_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/native/juce_win32_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/network/juce_IPAddress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/network/juce_IPAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/network/juce_MACAddress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/network/juce_MACAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/network/juce_NamedPipe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/network/juce_NamedPipe.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/network/juce_Socket.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/network/juce_Socket.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/network/juce_URL.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/network/juce_URL.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/network/juce_WebInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/network/juce_WebInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/streams/juce_BufferedInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/streams/juce_BufferedInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/streams/juce_FileInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/streams/juce_FileInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/streams/juce_InputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/streams/juce_InputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/streams/juce_InputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/streams/juce_MemoryInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/streams/juce_MemoryInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/streams/juce_OutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/streams/juce_OutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/streams/juce_SubregionStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/streams/juce_SubregionStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/streams/juce_URLInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/streams/juce_URLInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/system/juce_CompilerSupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/system/juce_CompilerWarnings.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/system/juce_PlatformDefs.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/system/juce_StandardHeader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/system/juce_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/system/juce_SystemStats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/system/juce_TargetPlatform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_Base64.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_Base64.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_CharacterFunctions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_CharacterFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_CharPointer_ASCII.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_CharPointer_UTF8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_CharPointer_UTF16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_CharPointer_UTF32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_Identifier.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_Identifier.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_LocalisedStrings.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_LocalisedStrings.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_NewLine.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_String.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_String.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_StringArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_StringArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_StringPairArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_StringPairArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_StringPool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_StringPool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_StringRef.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_TextDiff.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/text/juce_TextDiff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_ChildProcess.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_ChildProcess.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_CriticalSection.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_DynamicLibrary.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_InterProcessLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_Process.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_ReadWriteLock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_ReadWriteLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_ScopedLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_ScopedReadLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_ScopedWriteLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_SpinLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_Thread.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_Thread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_ThreadLocalValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_ThreadPool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_ThreadPool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_TimeSliceThread.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_TimeSliceThread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_WaitableEvent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/threads/juce_WaitableEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/time/juce_PerformanceCounter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/time/juce_PerformanceCounter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/time/juce_RelativeTime.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/time/juce_RelativeTime.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/time/juce_Time.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/time/juce_Time.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/unit_tests/juce_UnitTest.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/unit_tests/juce_UnitTest.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/unit_tests/juce_UnitTestCategories.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/xml/juce_XmlDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/xml/juce_XmlDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/xml/juce_XmlElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/xml/juce_XmlElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/adler32.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/compress.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/crc32.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/crc32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/deflate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/deflate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/infback.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/inffast.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/inffast.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/inffixed.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/inflate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/inflate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/inftrees.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/inftrees.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/trees.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/trees.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/uncompr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/zconf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/zconf.in.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/zlib.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/zutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/zlib/zutil.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/juce_ZipFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/zip/juce_ZipFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/juce_core.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/juce_core.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_core/juce_core.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/undomanager/juce_UndoableAction.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_CachedValue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_CachedValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_Value.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_Value.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_ValueTree.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_ValueTree.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/juce_data_structures.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/juce_data_structures.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_data_structures/juce_data_structures.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/containers/juce_AudioBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/containers/juce_AudioBlock_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/containers/juce_FixedSizeFunction.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/containers/juce_FixedSizeFunction_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/containers/juce_SIMDRegister.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/containers/juce_SIMDRegister_Impl.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/containers/juce_SIMDRegister_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/filter_design/juce_FilterDesign.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/filter_design/juce_FilterDesign.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/frequency/juce_Convolution.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/frequency/juce_Convolution.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/frequency/juce_Convolution_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/frequency/juce_FFT.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/frequency/juce_FFT.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/frequency/juce_FFT_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/frequency/juce_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/frequency/juce_Windowing.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_FastMathApproximations.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_LogRampedValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_LogRampedValue_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_LookupTable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_LookupTable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_Matrix.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_Matrix.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_Matrix_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_Phase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_Polynomial.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_SpecialFunctions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/maths/juce_SpecialFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/native/juce_avx_SIMDNativeOps.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/native/juce_avx_SIMDNativeOps.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/native/juce_fallback_SIMDNativeOps.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/native/juce_neon_SIMDNativeOps.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/native/juce_neon_SIMDNativeOps.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/native/juce_sse_SIMDNativeOps.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/native/juce_sse_SIMDNativeOps.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_BallisticsFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_BallisticsFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_DelayLine.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_DelayLine.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_DryWetMixer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_DryWetMixer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_FIRFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_FIRFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_FIRFilter_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_FirstOrderTPTFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_FirstOrderTPTFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_IIRFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_IIRFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_IIRFilter_Impl.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_LinkwitzRileyFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_LinkwitzRileyFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_Oversampling.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_Oversampling.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_Panner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_Panner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_ProcessContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_ProcessorChain.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_ProcessorChain_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_ProcessorDuplicator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_ProcessorWrapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_StateVariableFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_StateVariableTPTFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/processors/juce_StateVariableTPTFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Bias.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Chorus.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Chorus.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Compressor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Compressor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Gain.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_LadderFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_LadderFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Limiter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Limiter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_NoiseGate.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_NoiseGate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Oscillator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Phaser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Phaser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_Reverb.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/widgets/juce_WaveShaper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/juce_dsp.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/juce_dsp.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_dsp/juce_dsp.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/broadcasters/juce_ActionListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/broadcasters/juce_ChangeListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/interprocess/juce_NetworkServiceDiscovery.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/interprocess/juce_NetworkServiceDiscovery.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/messages/juce_ApplicationBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/messages/juce_ApplicationBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/messages/juce_CallbackMessage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/messages/juce_Initialisation.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/messages/juce_Message.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/messages/juce_MessageListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/messages/juce_MessageListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/messages/juce_MessageManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/messages/juce_MessageManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/messages/juce_MountedVolumeListChangeDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/messages/juce_NotificationType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/native/juce_android_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/native/juce_ios_MessageManager.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/native/juce_linux_EventLoop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/native/juce_linux_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/native/juce_mac_MessageManager.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/native/juce_osx_MessageQueue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/native/juce_ScopedLowPowerModeDisabler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/native/juce_ScopedLowPowerModeDisabler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/native/juce_win32_HiddenMessageWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/native/juce_win32_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/timers/juce_MultiTimer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/timers/juce_MultiTimer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/timers/juce_Timer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/timers/juce_Timer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/juce_events.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/juce_events.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_events/juce_events.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_Colour.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_Colour.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_ColourGradient.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_ColourGradient.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_Colours.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_Colours.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_FillType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_FillType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/colour/juce_PixelFormats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/effects/juce_GlowEffect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/effects/juce_GlowEffect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/effects/juce_ImageEffectFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_AttributedString.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_AttributedString.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_Font.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_Font.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_TextLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_TextLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_Typeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/fonts/juce_Typeface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_BorderSize.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_Line.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_Parallelogram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_Path.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_Path.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_PathIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_PathIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_Point.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_Rectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/geometry/juce_RectangleList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/cderror.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/changes to libjpeg for JUCE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcapimin.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcapistd.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jccoefct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jccolor.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcdctmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcinit.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcmainct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcmarker.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcmaster.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcomapi.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jconfig.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcparam.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcphuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcprepct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jcsample.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jctrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdapimin.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdapistd.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdatasrc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdcoefct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdcolor.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jddctmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdinput.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdmainct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdmarker.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdmaster.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdmerge.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdphuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdpostct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdsample.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jdtrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctflt.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctfst.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctint.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jidctflt.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jidctfst.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jidctint.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jidctred.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jinclude.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jmemmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jmemnobs.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jmemsys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jmorecfg.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jpegint.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jpeglib.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jquant1.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jquant2.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jutils.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/jversion.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/libpng_readme.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/png.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/png.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngconf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngdebug.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngerror.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngget.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pnginfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngmem.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngpread.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngpriv.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngread.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngrio.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngrtran.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngrutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngset.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngstruct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngtrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngwio.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngwrite.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngwtran.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/pnglib/pngwutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/juce_GIFLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/juce_JPEGLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/image_formats/juce_PNGLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/images/juce_Image.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/images/juce_Image.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/images/juce_ImageCache.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/images/juce_ImageCache.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_android_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_android_GraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_android_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_freetype_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_linux_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_linux_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_mac_Fonts.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_mac_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_RenderingHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_win32_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/native/juce_win32_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/placement/juce_Justification.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/juce_graphics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/juce_graphics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_graphics/juce_graphics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/enums/juce_AccessibilityActions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/enums/juce_AccessibilityEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/enums/juce_AccessibilityRole.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/interfaces/juce_AccessibilityCellInterface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/interfaces/juce_AccessibilityTableInterface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/interfaces/juce_AccessibilityTextInterface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/interfaces/juce_AccessibilityValueInterface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/juce_AccessibilityHandler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/juce_AccessibilityHandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/accessibility/juce_AccessibilityState.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/application/juce_Application.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/application/juce_Application.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_Button.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_Button.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandID.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_CachedComponentImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_Component.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_Component.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_ComponentTraverser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_FocusTraverser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_FocusTraverser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/desktop/juce_Desktop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/desktop/juce_Desktop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/desktop/juce_Displays.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/desktop/juce_Displays.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/drawables/juce_SVGParser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FilePreviewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_SystemClipboard.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_TextEditorKeyMapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/keyboard/juce_TextInputTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPosition.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPositionBehaviours.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_FlexItem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_Grid.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_Grid.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_GridItem.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_GridItem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_Viewport.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/layout/juce_Viewport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_FileDragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_LassoComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_SelectedItemSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_TextDragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/mouse/juce_TooltipClient.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_AccessibilityTextHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_android_Accessibility.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_ios_Accessibility.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_mac_Accessibility.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_mac_AccessibilitySharedCode.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_Accessibility.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_AccessibilityElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_AccessibilityElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAExpandCollapseProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAGridItemProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAGridProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAInvokeProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAProviderBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAProviders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIARangeValueProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIASelectionProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIATextProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAToggleProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIATransformProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAValueProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_UIAWindowProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/accessibility/juce_win32_WindowsUIAWrapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/x11/juce_linux_X11_DragAndDrop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/x11/juce_linux_X11_Symbols.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/x11/juce_linux_X11_Symbols.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/x11/juce_linux_XWindowSystem.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/x11/juce_linux_XWindowSystem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_android_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_android_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_android_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_common_MimeTypes.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_ios_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_ios_FileChooser.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_ios_UIViewComponentPeer.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_ios_Windowing.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_linux_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_linux_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_mac_FileChooser.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_mac_MainMenu.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_mac_MouseCursor.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_mac_NSViewComponentPeer.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_mac_Windowing.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_MultiTouchMapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_win32_DragAndDrop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_win32_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_win32_ScopedThreadDPIAwarenessSetter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/native/juce_win32_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_Label.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_Label.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_Slider.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_Slider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemFactory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_MessageBoxOptions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_NativeMessageBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/juce_gui_basics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/juce_gui_basics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_basics/juce_gui_basics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_CodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniserFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/embedding/juce_ActiveXControlComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/embedding/juce_AndroidViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/embedding/juce_HWNDComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/embedding/juce_NSViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/embedding/juce_ScopedDPIAwarenessDisabler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/embedding/juce_UIViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/embedding/juce_XEmbedComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_AppleRemote.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/misc/juce_WebBrowserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_android_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_android_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_AndroidViewComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_ios_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_ios_UIViewComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_linux_X11_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_linux_X11_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_linux_XEmbedComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_mac_AppleRemote.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_mac_CarbonViewWrapperComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_mac_NSViewComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_mac_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_mac_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_mac_WebBrowserComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_win32_ActiveXComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_win32_HWNDComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_win32_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/native/juce_win32_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/juce_gui_extra.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/juce_gui_extra.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../JUCE/JUCE/modules/juce_gui_extra/juce_gui_extra.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../JuceLibraryCode/BinaryData.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../JuceLibraryCode/JuceHeader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../JuceLibraryCode/JucePluginDefines.h" PROPERTIES HEADER_FILE_ONLY TRUE)

target_compile_options( ${BINARY_NAME} PRIVATE "-fsigned-char" )

if( JUCE_BUILD_CONFIGURATION MATCHES "DEBUG" )
    target_compile_options( ${BINARY_NAME} PRIVATE)
endif()

if( JUCE_BUILD_CONFIGURATION MATCHES "RELEASE" )
    target_compile_options( ${BINARY_NAME} PRIVATE)
endif()

find_library(log "log")
find_library(android "android")
find_library(glesv2 "GLESv2")
find_library(egl "EGL")

target_link_libraries( ${BINARY_NAME}

    ${log}
    ${android}
    ${glesv2}
    ${egl}
    "cpufeatures"
    "oboe"
)
