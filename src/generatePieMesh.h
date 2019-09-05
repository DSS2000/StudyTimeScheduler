//
//  ofMesh.hpp
//  StudyTimeScheduler
//
//  Created by Dhruv Sirsikar on 4/19/19.
//

#pragma once
#include "ofMain.h"
//General code structure taken from https://gist.github.com/rc1/3715e673ef175b5e0c93
const int kRadians = 360;
const double kBase = 0;
const double kFull = 1.0;

ofMesh generatePieMesh(float value, float start, float end, float radius, float segments) {
    ofMesh mesh;
    mesh.setMode( OF_PRIMITIVE_TRIANGLE_FAN );
    mesh.addVertex(ofVec3f::zero());
    for ( float i = 0; i <= segments; i++ ) {
        ofMatrix4x4 matrix;
        matrix.translate( 0.0f, radius, 0.0f );
        matrix.rotate(kRadians * (i / segments), kBase, kBase, kFull);
        matrix.scale(kFull, -kFull, kFull);
        ofVec3f p = ofVec3f::zero() * matrix;
        if (i >= start && i <= end) {
            mesh.addVertex(p);
        }
    }
    return mesh;
}
