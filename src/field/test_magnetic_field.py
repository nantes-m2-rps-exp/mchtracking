import mchfield
import pytest
import math

def test_createMinusMinusFieldMap():
    field = mchfield.MagneticField.createFieldMap()
    bz0 = field.solenoidField()
    nomBz = -5.00685
    assert bz0 == pytest.approx(nomBz,0.001)

def test_createPlusPlusFieldMap():
    field = mchfield.MagneticField.createFieldMap(30000,6000);
    bz0 = field.solenoidField()
    nomBz = 5.00685
    assert bz0 == pytest.approx(nomBz,0.001)
