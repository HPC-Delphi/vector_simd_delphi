unit IntelSIMD;

interface

uses
  System.SysUtils;

const
  DLLNAME = 'intel_simd_delphi.dll';

function VLengthDouble:Integer; cdecl; external DLLNAME name 'vlength_double';
procedure VectorFMA(A, B, C: PDouble); cdecl; external DLLNAME name 'vfma_double';
procedure VectorAdd(A, B, C: PDouble); cdecl; external DLLNAME name 'vadd_double';
procedure VectorMul(A, B, C: PDouble); cdecl; external DLLNAME name 'vmul_double';
procedure VectorReduce(A: PDouble; Sum: PDouble); cdecl; external DLLNAME name 'vreduce_double';

implementation

end.
