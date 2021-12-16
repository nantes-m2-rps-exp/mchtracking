import mchfield
import mchtracking
import pytest
import math

def test_setField():
    mchtracking.TrackExtrap.setField()
    assert mchtracking.TrackExtrap.isFieldON()==False

def test_isFieldON():
    mchtracking.TrackFitter().initField(30000.0,6000.0)
    assert mchtracking.TrackExtrap.isFieldON()==True
