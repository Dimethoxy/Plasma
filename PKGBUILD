# Maintainer: Lunix (David Hess) <davidhess336@gmx.de>
pkgname='dimethoxy-plasma-bin'
pkgver=1.2.1
pkgrel=1
pkgdesc="Asymmetrical Distortion Effect for VST3 and LV2 compatible hosts"
arch=('x86_64')
url="https://github.com/Dimethoxy/Plasma"
license=('GPL3')
provides=('dimethoxy-plasma')
source=("https://github.com/Dimethoxy/Plasma/releases/download/v$pkgver/plasma-v$pkgver-linux.tar.gz")
sha256sums=('0111200a8294fcb50312fde794e6f1f3cca5bef9da8ef515b786d3a86fb15308')

package() {
    # Define new directories
    install -d "$pkgdir/usr/lib/vst3/Dimethoxy/Plasma" "$pkgdir/usr/lib/lv2/Dimethoxy/Plasma"
    install -d "$pkgdir/usr/share/licenses/$pkgname"

    # Install plugins (use cp -r for directories)
    cp -r "$srcdir/Plasma.vst3" "$pkgdir/usr/lib/vst3/Dimethoxy/Plasma/"
    cp -r "$srcdir/Plasma.lv2" "$pkgdir/usr/lib/lv2/Dimethoxy/Plasma/"

    # Download and install the LICENSE from the remote URL
    curl -L "https://raw.githubusercontent.com/Dimethoxy/Plasma/refs/heads/main/LICENSE" -o "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}