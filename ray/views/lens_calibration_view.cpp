#include <ray/views/lens_calibration_view.h>
#include <ray/views/intrinsics_view.h>
#include <ray/views/brown_conrady_view.h>
#include <wxpex/button.h>
#include <wxpex/check_box.h>
#include <wxpex/field.h>
#include <wxpex/labeled_widget.h>
#include <draw/views/cross_shape_view.h>


namespace ray
{

namespace views
{


LensCalibrationView::LensCalibrationView(
    wxWindow *parent,
    const LensCalibrationControl<double> &control)
    :
    wxPanel(parent, wxID_ANY)
{
    auto intrinsicsView =
        new IntrinsicsView(
            this,
            "Intrinsics",
            control.intrinsics);

    auto brownConradyView =
        new BrownConradyView(
            this,
            "Brown-Conrady",
            control.distortion);

    auto sizer = wxpex::LayoutItems(
        wxpex::verticalItems,
        intrinsicsView,
        brownConradyView);

    this->SetSizer(sizer.release());
}


} // end namespace views

} // end namespace ray
