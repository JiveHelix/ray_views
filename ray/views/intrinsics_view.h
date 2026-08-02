#pragma once


#include <wxpex/wxshim.h>
#include <wxpex/static_box.h>
#include <wxpex/labeled_widget.h>
#include <ray/intrinsics.h>


namespace ray
{


namespace views
{


class IntrinsicsView: public wxpex::StaticBox
{
public:
    using LayoutOptions = wxpex::LayoutOptions;

    IntrinsicsView(
        wxWindow *parent,
        const std::string &name,
        const ray::IntrinsicsControl<double> &control,
        const LayoutOptions &layoutOptions = LayoutOptions{});
};


} // end namespace views

} // end namespace ray
