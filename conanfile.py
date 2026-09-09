from conan import ConanFile


class RayViewsConan(ConanFile):
    name = "ray_views"
    version = "1.0.0"

    python_requires = "boiler/0.2"
    python_requires_extend = "boiler.LibraryConanFile"

    license = "MIT"
    author = "Jive Helix (jivehelix@gmail.com)"
    url = "https://github.com/JiveHelix/ray_views"
    description = "GUIs for Camera calibration tools."

    topics = (
        "Camera Calibration",
        "Distortion")

    def layout(self):
        super().layout()
        self.cpp.build.libdirs = ["ray"]

    def build_requirements(self):
        self.test_requires("catch2/2.13.9")

    def requirements(self):
        self.requires("ray/[~1]", transitive_headers=True)
        self.requires("wxpex/[>=1.0 <2]", transitive_headers=True)
        self.requires("draw/[~0.3]", transitive_headers=True)
