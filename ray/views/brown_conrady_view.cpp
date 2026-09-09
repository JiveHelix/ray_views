#include <ray/views/brown_conrady_view.h>
#include <ray/views/direction_view.h>
#include <wxpex/view.h>
#include <wxpex/labeled_widget.h>
#include <wxpex/layout_items.h>


namespace ray
{


namespace views
{


BrownConradyView::BrownConradyView(
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
        "k1:",
        CreateView<4>(this, control.k1));

    auto k2 = wxpex::LabeledWidget(
        this,
        "k2:",
        CreateView<4>(this, control.k2));

    auto p1 = wxpex::LabeledWidget(
        this,
        "p1:",
        CreateView<4>(this, control.p1));

    auto p2 = wxpex::LabeledWidget(
        this,
        "p2:",
        CreateView<4>(this, control.p2));

    auto k3 = wxpex::LabeledWidget(
        this,
        "k3:",
        CreateView<4>(this, control.k3));

    auto direction = new DirectionView(this, control.direction);

    auto controlsSizer = wxpex::LayoutLabeled(
        layoutOptions,
        k1,
        k2,
        p1,
        p2,
        k3);

    auto sizer = LayoutItems(
        wxpex::verticalItems,
        controlsSizer.release(),
        direction);

    this->ConfigureSizer(std::move(sizer));
}


} // end namespace views

} // end namespace ray
