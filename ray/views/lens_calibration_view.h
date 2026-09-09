#pragma once


#include <wxpex/wxshim.h>
#include <ray/lens_calibration.h>


namespace ray
{

namespace views
{


class LensCalibrationView: public wxPanel
{
public:
    LensCalibrationView(
        wxWindow *parent,
        const LensCalibrationControl<double> &control);
};


} // end namespace ray

} // end namespace views
