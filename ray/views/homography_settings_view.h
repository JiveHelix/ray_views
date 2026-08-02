#pragma once


#include <wxpex/labeled_widget.h>
#include <wxpex/collapsible.h>
#include <ray/homography_settings.h>


namespace ray
{

namespace views
{


class HomographySettingsView: public wxpex::Collapsible
{
public:
    using LayoutOptions = wxpex::LayoutOptions;

    HomographySettingsView(
        wxWindow *parent,
        HomographyControl control,
        const LayoutOptions &layoutOptions = LayoutOptions{});
};


} // end namespace views

} // end namespace ray
