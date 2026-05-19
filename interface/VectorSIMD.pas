unit VectorSIMD;

interface

uses
  System.SysUtils;

const
  DLLNAME = 'vector_simd_delphi.dll';

procedure VectorAdd(A, B, C: PDouble; Length: Integer); cdecl; external DLLNAME name 'vadd_double';
procedure VectorMul(A, B, C: PDouble; Length: Integer); cdecl; external DLLNAME name 'vmul_double';
procedure VectorFMA(A, B, C: PDouble; Length: Integer); cdecl; external DLLNAME name 'vfma_double';
procedure VectorReduce(A: PDouble; Sum: PDouble; Length: Integer); cdecl; external DLLNAME name 'vreduce_double';

implementation

end.
