unit Vector;

interface

uses
  System.SysUtils;

types
  TVectorD = PDouble;

const
  DLLNAME = 'vector_delphi.dll';

function VLengthDouble:Integer; cdecl; external DLLNAME name 'vlength_double';
function VectorLoad(A: PDouble): TVectorD; cdecl; external DLLNAME name 'vload_double';
function VectorLoad(A: TVectorD): PDouble; cdecl; external DLLNAME name 'vload_double';
function VectorAdd(A, B, C: TVectorD); cdecl; external DLLNAME name 'vadd_double';
function VectorMul(A, B, C: TVectorD); cdecl; external DLLNAME name 'vmul_double';

implementation

end.
