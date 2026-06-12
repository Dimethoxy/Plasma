# Plasma

Plasma is a free & open-source distortion powerhouse for VST3 hosts. Originally designed for Hardstyle, Gabber, Hardcore, and anything that needs raw, aggressive energy, Plasma lets you twist and destroy your sound with 12 brutal distortion styles and filters with extreme resonance capabilities.

But don’t box it in—Plasma is a sound design weapon for any genre. Use it to add bite to guitars, weight to basslines, or grit to synths. Whether you're sculpting punishing drops or crushing breakbeats, Plasma delivers.

<div align="center">
  <img src="https://github.com/Dimethoxy/Plasma/blob/main/CompressedPreview.webp?raw=true" alt="Image of the GUI" style="width: 60%;">
</div>

## 🔥 Features

- **Free & Open-Source** – No paywalls, no restrictions
- **Asymmetrical Distortion** – Analog-inspired digital mayhem
- **12 Distortion Styles** – From subtle warmth to total destruction
- **4 Filters** – Highpass, lowpass, dual, and peak filters with up to 64dB resonance for extreme sound shaping
- **Girth Effect** – Uses noise to erode the sound, adding high-end dirt and texture. 
- **Oscilloscope** – See your sound shaping in real time
- **Customizable UI** – Minimalist vector interface with color options
- **Scalable UI** – Perfect for high-res screens
- **Intuitive Workflow** – Get to your sound quickly with easy-to-navigate controls.
- **Low CPU impact** – Crush your sounds, not your processor
- **Cross-platform** – Supports Windows, macOS, and Linux
- **Multi-Format Support** – Works with VST3, LV2, and AU formats.
- **Regular Updates** – Continuous improvements and new features
- **Privacy First** – We take your privacy seriously, no tracking or data collection

## 💖 Donations

If you love Plasma, consider supporting its development.
[Donate via PayPal](https://www.paypal.com/donate/?hosted_button_id=8SJXCUYV5ZHKG)

Your donation helps keep Plasma free, improves future updates, and supports the creation of new audio tools for the community. Thank you!
  
## 🔻 Downloads

You can download our pre-built binaries for Windows, MacOS and Linux [here](https://github.com/Dimethoxy/Plasma/releases).

## 🐧 Arch Linux

There is now an AUR package available for Arch Linux users.

You can install it easily by using your favorite AUR helper (e.g. [yay](https://github.com/Jguer/yay)):
```bash
yay -S dimethoxy-plasma-bin
```
Or manually:

```bash
sudo pacman -S --needed base-devel
git clone https://aur.archlinux.org/dimethoxy-plasma-bin.git
cd dimethoxy-plasma-bin
makepkg -si
```
We ensure Arch Linux users receive updates as soon as they're available, directly through the AUR.

## ⭐ Star History

[![Star History Chart](https://api.star-history.com/chart?repos=Dimethoxy/Disflux%2CDimethoxy/Plasma&type=date&legend=bottom-right)](https://www.star-history.com/?repos=Dimethoxy%2FDisflux%2CDimethoxy%2FPlasma&type=date&legend=bottom-right)

## 💻 System Requirements

### Windows

- Windows 10 or later
- 64-bit Intel/AMD quad-core CPU or equivalent
- 50 MB disk space
- 64-bit DAW with VST3 support
- ARM versions of Windows are NOT supported

### MacOS

- MacOS 10.13 or later
- Intel or Apple Silicon CPU
- At least 50 MB of free disk space
- 64-bit DAW with VST3 or AU support

### Linux

- Mainstream x86_64 Linux distribution
- 64-bit Intel/AMD quad-core CPU or equivalent
- At least 50 MB of free disk space
- 64-bit DAW with VST3 or LV2 support

## 🛠️ Build Instructions

If you want to compile Plasma from source yourself, follow these steps:

### Requirements

Before building Plasma, ensure you have the following:

#### JUCE Build Requirements

- **C++ Standard:** 17
- **macOS/iOS:** Xcode 12.4 (Intel macOS 10.15.4, Apple Silicon macOS 11.0)
- **Windows:** Visual Studio 2019 (Windows 10)
- **Linux:** g++ 7.0 or Clang 6.0
- **Android:** Android Studio (NDK 26)

For full details on dependencies, refer to the [JUCE documentation](https://github.com/juce-framework/JUCE?tab=readme-ov-file#minimum-system-requirements).  

#### Additional Requirements

- **Git** – Required for cloning the repository. If you haven't installed it yet, follow the [Git installation guide](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git).
- **Linux Users:** You must also install the [JUCE dependencies for Linux](https://github.com/juce-framework/JUCE/blob/master/docs/Linux%20Dependencies.md).

### Steps to Build

1. Clone the Plasma Repository: 
```bash
git clone https://github.com/Dimethoxy/Plasma.git
```
2. Download JUCE 8 from the [JUCE releases page](https://github.com/juce-framework/JUCE/releases/tag/8.0.6).
3. Extract JUCE to a location on your computer.
4. Open the Projucer app inside the JUCE folder you just extracted.
5. In Projucer, go to the top menu, click on File, then select Open.
6. Navigate to the cloned Plasma repository and choose the `Plasma.jucer` file to open the project.
7. Make sure to save the project once, this will generate the build files.
8. Build the project:
   - Windows/MacOS:
     - After saving, click the button at the top center of Projucer to open it in Visual Studio (Windows) or Xcode (macOS).
     - Now Build the project as usual in the IDE.
   - Linux
     - Navigate to the `Builds/LinuxMakefile/` folder inside the Plasma project.
     - Run the Makefile with one of these commands:
       ```bash
       make CONFIG=Release
       ```
       ```bash
       make CONFIG=Debug
       ```

## 📜 License

The source code is licensed under the **GPLv3**. If you build or distribute it, you must comply with [GNU GPLv3](http://www.gnu.org/licenses/).

## ⚠️ Warranty

You and your end-users use the software at your own risk.

**THE SOFTWARE IS PROVIDED “AS IS,” WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING FROM, OUT OF, OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.**
