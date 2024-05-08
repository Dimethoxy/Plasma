# Plasma

Plasma is a free digital audio effect for VST3 hosts. With its asymmetrical distortion and warm filters, Plasma is the perfect tool for creating aggressive and unique sounds in hard dance genres like Gabber, Hardstyle, and Hardcore.

However, Plasma is not just limited to hard dance genres – it's a versatile tool that can be used in any music production scenario. Use it to add grit and character to your guitar tracks or to create punishing basslines in your dubstep tracks. The possibilities with Plasma are endless.

<div align="center">
  <img src="https://github.com/Dimethoxy/Plasma/blob/master/Preview.png?raw=true" alt="Image of the GUI">
</div>

## Features

- Free (as in freedom) and open-source
- Asymmetrical distortion
- 10 different distortion styles
- 3 filters for shaping the tone
- Innovative "Girth" effect to add treble to your sound
- Oscilloscope to visualize the output waveform
- Color-customizable minimalistic vector GUI
- Scalable for high-resolution displays
- Very low resource consumption
- Support for Windows, MacOS, and Linux

## Downloads

You can download our pre-built binaries for Windows and MacOS [here](https://github.com/Dimethoxy/Plasma/releases). \
For Linux use our latest [pre-release version](https://github.com/Dimethoxy/Plasma/releases/tag/1.1.0).

## Installation

### Windows - VST3:

1. **Download:** Download Plasma from [here](https://github.com/Dimethoxy/Plasma/releases).
2. **Unzip:** Unzip the downloaded archive. \
   Ensure you have a utility like WinRAR or 7-Zip installed for this process.
3. **Locate Files:** After extraction, you should find a file named `Plasma.vst3`.
4. **Move Files:** Move the `Plasma.vst3` file to your VST3 plugins directory. \
   The default location for VST3 plugins on Windows is `%CommonProgramFiles%\VST3`.

### MacOS - VST3:

1. **Download:** Download Plasma from [here](https://github.com/Dimethoxy/Plasma/releases).
2. **Unzip:** Unzip the downloaded archive. \
   Most MacOS systems can unzip files by double-clicking the zip file.
3. **Locate Files:** After extraction, you should find a file named `Plasma.vst3`.
4. **Move Files:** Move the `Plasma.vst3` file to your VST3 plugins directory. \
   The default location for VST3 plugins on MacOS is `/Library/Audio/Plug-ins/VST3`.
5. **Remove Quarantine:**
   - Open the folder containing the "Plasma.vst3" file in Finder.
   - Open Terminal.
   - Type the following command: `sudo xattr -rd com.apple.quarantine` (Note: Do not hit enter yet).
   - Ensure there is a single space after "quarantine".
   - Drag and drop the "Plasma.vst3" file into the Terminal, its path should now appear in the Terminal.
   - Hit enter and enter your administrator password if prompted.

### Linux - VST3:

1. **Download:** Download the pre-release version of Plasma 1.1.0 from [here](https://github.com/Dimethoxy/Plasma/releases/tag/1.1.0).
2. **Unzip:** Extract the downloaded archive. You can use archive manager tools like tar.
3. **Locate Files:** After extraction, you should find a file named `Plasma.so`.
4. **Move Files:** Move the `Plasma.so` file to your VST3 plugins directory. \
   The location of this directory may vary depending on your Linux distribution and DAW. \
   Common directories include `~/.vst3/` or `/usr/lib/vst3/`.

## System Requirements

### Windows

- Windows 10 or later
- Intel or AMD CPU with a 64-bit quad-core processor
- At least 50 MB of free disk space
- A compatible 64-bit host DAW that supports VST3 plugins
- ARM versions of Windows are NOT supported

### MacOS

- MacOS 10.13 or later
- Intel or Apple Silicon CPU
- At least 100 MB of free disk space
- A compatible 64-bit host DAW that supports VST3 plugins

### Linux

- Mainstream x86_64 Linux distribution
- Intel or AMD CPU with a 64-bit quad-core processor
- At least 80 MB of free disk space
- A compatible 64-bit host DAW that supports VST3 plugins

## Donations

If you have enjoyed using our software, please consider donating.
[Donate via PayPal](https://www.paypal.com/donate/?hosted_button_id=8SJXCUYV5ZHKG)

We are dedicated to providing high-quality audio tools to the community for free, and your support helps us to continue our work. Your donation will contribute to maintaining and improving our software, as well as supporting the development of new tools and features. We greatly appreciate your support and thank you for helping us to continue our work.

## License

The source code is licensed under the **GPLv3**. If you download the source or create builds, you must comply with that license. For more information, visit [http://www.gnu.org/licenses/](http://www.gnu.org/licenses/).

## Warranty

You and your end-users use the software at your own risk.

**THE SOFTWARE IS PROVIDED “AS IS,” WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING FROM, OUT OF, OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.**
