#pragma once


#include <wxpex/combo_box.h>
#include <tau/vector2d.h>



namespace ray
{

namespace views
{


class DirectionSelector: public wxControl
{
public:
    using Control = ray::distortion::DirectionControl;

    using Widget =
        wxpex::ComboBox
        <
            distortion::DirectionControl,
            distortion::DirectionConverter
        >;

    DirectionSelector(wxWindow *parent, const Control &control)
        :
        wxControl(parent, wxID_ANY)
    {
        using namespace wxpex;

        auto label = new wxStaticText(this, wxID_ANY, "Direction:");
        auto direction = new Widget(this, control);

        auto sizer = std::make_unique<wxBoxSizer>(wxHORIZONTAL);
        sizer->Add(label, 0, wxRIGHT, 3);
        sizer->Add(direction, 1, wxRIGHT, 6);

        this->SetSizerAndFit(sizer.release());
    }
};


class DirectionView: public wxControl
{
public:
    using Control = ray::distortion::DirectionControl;

    using Widget =
        wxpex::ReadOnlySelect
        <
            distortion::DirectionControl,
            distortion::DirectionConverter
        >;

    DirectionView(wxWindow *parent, const Control &control)
        :
        wxControl(parent, wxID_ANY)
    {
        using namespace wxpex;

        auto label = new wxStaticText(this, wxID_ANY, "Direction:");
        auto direction = new Widget(this, control);

        auto sizer = std::make_unique<wxBoxSizer>(wxHORIZONTAL);
        sizer->Add(label, 0, wxRIGHT, 3);
        sizer->Add(direction, 1, wxRIGHT, 6);

        this->SetSizerAndFit(sizer.release());
    }
};


} // end namespace views

} // end namespace ray
