#include <ray/views/calibration_result_view.h>
#include <ray/views/lens_calibration_view.h>
#include <wxpex/field.h>
#include <wxpex/labeled_widget.h>
#include <draw/views/cross_shape_view.h>


namespace ray
{

namespace views
{


CalibrationResultView::CalibrationResultView(
    wxWindow *parent,
    const CalibrationResultControl<double> &control)
    :
    wxPanel(parent, wxID_ANY)
{
    auto lensCalibration = new LensCalibrationView(
        this,
        control.lensCalibration);

    auto rmsResidual = wxpex::LabeledWidget(
        this,
        "rmsReprojectionError (pixels)",
        wxpex::CreateView<5>(
            this,
            control.rmsReprojectionError_pixels));

    auto sizer = wxpex::LayoutItems(
        wxpex::verticalItems,
        lensCalibration,
        rmsResidual.Layout());

    this->SetSizer(sizer.release());
}


} // end namespace views

} // end namespace ray
