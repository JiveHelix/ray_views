#include <ray/views/distortion_view.h>
#include <wxpex/view.h>


namespace ray
{


namespace views
{


DistortionView::DistortionView(
    wxWindow *parent,
    const std::string &name,
    const ray::distortion::BrownConradyControl<double> &control,
    const LayoutOptions &layoutOptions)
    :
    wxpex::StaticBox(parent, name)
{
    using wxpex::CreateView;

    auto k1 = wxpex::LabeledWidget(
        this,
        "k1",
        CreateView<4>(this, control.k1));

    auto k2 = wxpex::LabeledWidget(
        this,
        "k2",
        CreateView<4>(this, control.k2));

    auto p1 = wxpex::LabeledWidget(
        this,
        "p1",
        CreateView<4>(this, control.p1));

    auto p2 = wxpex::LabeledWidget(
        this,
        "p2",
        CreateView<4>(this, control.p2));

    auto k3 = wxpex::LabeledWidget(
        this,
        "k3",
        CreateView<4>(this, control.k3));

    auto controlsSizer = LayoutLabeled(
        layoutOptions,
        k1,
        k2,
        p1,
        p2,
        k3);

    this->ConfigureSizer(std::move(controlsSizer));
}


} // end namespace views

} // end namespace ray
