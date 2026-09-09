#pragma once


#include <wxpex/wxshim.h>
#include <ray/calibration_result.h>


namespace ray
{

namespace views
{


class CalibrationResultView: public wxPanel
{
public:
    CalibrationResultView(
        wxWindow *parent,
        const CalibrationResultControl<double> &control);
};


} // end namespace ray

} // end namespace views
