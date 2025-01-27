// Uniforms
#pragma bind_symbol ( WORLDVIEWPROJ , c0 , c3 )

// Inputs, attribute
#pragma bind_symbol ( aPosition.xyz , v0 )

// Outputs, varing
#pragma output_map ( position , o0 )

def c19, 1.000000, -1.000000, 1.000000, 1.000000
def c51, 0.000000, 0.000000, 0.250000, 0.022346

normalizedepth:
mul r0.z, r0.zzzz, r0.wwww
add r0.z, -c51.zzzz, r0.zzzz
mul r0.z, c51.wwww, r0.zzzz
ret
endnormalizedepth:

main:
dp4 r0.x, c0.xyzw, v0.xyzw
dp4 r0.y, c1.xyzw, v0.xyzw
dp4 r0.z, c2.xyzw, v0.xyzw
dp4 r0.w, c3.xyzw, v0.xyzw
mov r0.xyz, r0.yxzz
mul o0.xyzw, c19.xyzw, r0.xyzw
end
endmain