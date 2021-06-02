#include"GUIhelp.h"
#include<vector>

void drawQuads(const std::vector<Coordinates>& points, const Color& color) {
	glBegin(GL_QUADS);
	glColor3f(color.r, color.g, color.b);
	for (int i(0); i < points.size(); ++i) {
		glVertex3f(points[i].x, points[i].y, points[i].z);
	}
	glEnd();

	glLineWidth(3.0f);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (int i(0); i < points.size(); ++i) {
		glVertex3f(points[i].x, points[i].y, points[i].z);
	}
	glEnd();
}

void drawSmallCube(const SmallCube& cube, const Coordinates& coords, GLfloat size) {
	std::vector<Coordinates> points(8);
	points[0] = coords;
	points[1] = { coords.x, coords.y, coords.z - size};
	points[2] = { coords.x + size, coords.y, coords.z - size };
	points[3] = { coords.x + size, coords.y, coords.z };
	points[4] = { coords.x, coords.y - size, coords.z };
	points[5] = { coords.x, coords.y - size, coords.z - size };
	points[6] = { coords.x + size, coords.y - size, coords.z - size };
	points[7] = { coords.x + size, coords.y - size, coords.z };

	drawQuads(std::vector<Coordinates>({ points[0], points[3], points[7], points[4] }), cube.getFront());
	drawQuads(std::vector<Coordinates>({ points[0], points[1], points[5], points[4] }), cube.getLeft());
	drawQuads(std::vector<Coordinates>({ points[1], points[2], points[6], points[5] }), cube.getBack());
	drawQuads(std::vector<Coordinates>({ points[2], points[3], points[7], points[6] }), cube.getRight());
	drawQuads(std::vector<Coordinates>({ points[4], points[5], points[6], points[7] }), cube.getDown());
	drawQuads(std::vector<Coordinates>({ points[0], points[1], points[2], points[3] }), cube.getUp());
}

//void drawRubicsCube(const RubicsCube& cube, const Coordinates& coords, GLfloat size) {
//	for (int x(0); x < 3; ++x) {
//		for (int y(0); y < 3; ++y) {
//			for (int z(0); z < 3; ++z) {
//				Coordinates leftUpFrontAngle = coords;
//				if (x == 1) {
//					leftUpFrontAngle.x += size;
//				} else if (x == 2) {
//					leftUpFrontAngle.x += 2 * size;
//				}
//				if (y == 1) {
//					leftUpFrontAngle.y -= size;
//				} else if (y == 2) {
//					leftUpFrontAngle.y -= 2 * size;
//				}
//				if (z == 1) {
//					leftUpFrontAngle.z -= size;
//				} else if (z == 2) {
//					leftUpFrontAngle.z -= 2 * size;
//				}
//				drawSmallCube(cube.getCube(x, y, z), leftUpFrontAngle, size);
//			}
//		}
//	}
//}
