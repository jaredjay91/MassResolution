#!/bin/bash
#<<COMMENT
root -b -l -q "getWidthsOftnpFits_PbPbJpsi.C(0)"
root -b -l -q "getWidthsOftnpFits_PbPbJpsi.C(1)"
root -b -l -q "getWidthsOftnpFits_PbPbZ.C(0)"
root -b -l -q "getWidthsOftnpFits_PbPbZ.C(1)"
root -b -l -q "getWidthsOftnpFits_pPbJpsi.C(0)"
root -b -l -q "getWidthsOftnpFits_pPbJpsi.C(1)"
root -b -l -q "getWidthsOftnpFits_pPbZ.C(0)"
root -b -l -q "getWidthsOftnpFits_pPbZ.C(1)"
root -b -l -q "getWidthsOftnpFits_ppJpsi.C(0)"
root -b -l -q "getWidthsOftnpFits_ppJpsi.C(1)"
root -b -l -q "getWidthsOftnpFits_ppZ.C(0)"
root -b -l -q "getWidthsOftnpFits_ppZ.C(1)"

root -b -l -q "getWidthsOftnpFits_ptPbPbJpsi.C(0)"
root -b -l -q "getWidthsOftnpFits_ptPbPbJpsi.C(1)"
root -b -l -q "getWidthsOftnpFits_ptPbPbZ.C(0)"
root -b -l -q "getWidthsOftnpFits_ptPbPbZ.C(1)"
root -b -l -q "getWidthsOftnpFits_ptpPbJpsi.C(0)"
root -b -l -q "getWidthsOftnpFits_ptpPbJpsi.C(1)"
root -b -l -q "getWidthsOftnpFits_ptpPbZ.C(0)"
root -b -l -q "getWidthsOftnpFits_ptpPbZ.C(1)"
root -b -l -q "getWidthsOftnpFits_ptppJpsi.C(0)"
root -b -l -q "getWidthsOftnpFits_ptppJpsi.C(1)"
root -b -l -q "getWidthsOftnpFits_ptppZ.C(0)"
root -b -l -q "getWidthsOftnpFits_ptppZ.C(1)"
#COMMENT
root -b -l -q mergeGraphs.C
root -b -l -q mergePtGraphs.C

