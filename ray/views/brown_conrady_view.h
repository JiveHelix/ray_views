#pragma once


#include <wxpex/wxshim.h>
#include <wxpex/static_box.h>
#include <wxpex/labeled_widget.h>
#include <ray/intrinsics.h>
#include <ray/distortion.h>


namespace ray
{


namespace views
{


class BrownConradyView: public wxpex::StaticBox
{
public:
    using LayoutOptions = wxpex::LayoutOptions;

    BrownConradyView(
        wxWindow *parent,
        const std::string &name,
        const ray::distortion::BrownConradyControl<double> &control,
        const LayoutOptions &layoutOptions = LayoutOptions{});
};


} // end namespace views

} // end namespace ray
