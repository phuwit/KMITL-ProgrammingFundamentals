#include <stdio.h>
#include <math.h>

struct Coords {
    int x;
    int y;
};

struct CoordsPairInfo {
    struct Coords coords1;
    struct Coords coords2;
    double distance;
};

double get_distance (struct Coords p1, struct Coords p2) {
    // AB = \sqrt{[x_{2}-x_{1}]^{2}+[y_{2}-y_{1}]^{2}}
    double distance = sqrt(fabs((pow(p2.x, 2) - pow(p1.x, 2)) + (pow(p2.y, 2) - pow(p1.y, 2))));
    return distance;
}

int main () {
    int MAX_COORDS = 5;
    struct Coords coordsList[MAX_COORDS];

    for (int i = 0; i < MAX_COORDS; i++) {
        scanf("%d %d", &coordsList[i].x, &coordsList[i].y);
    }

    struct CoordsPairInfo coordsPairinfo[MAX_COORDS * 2];
    int coordsPairInfoIndex = 0;
    int maxDistanceCoordsPairInfoIndex = 0;
    for (int i = 0; i < MAX_COORDS; i++) {
        for (int j = 0; j < i; j++) {
            coordsPairinfo[coordsPairInfoIndex].coords1 = coordsList[i];
            coordsPairinfo[coordsPairInfoIndex].coords2 = coordsList[j];
            coordsPairinfo[coordsPairInfoIndex].distance = get_distance(coordsList[i], coordsList[j]);

            if (coordsPairinfo[coordsPairInfoIndex].distance > coordsPairinfo[maxDistanceCoordsPairInfoIndex].distance) {
                maxDistanceCoordsPairInfoIndex = coordsPairInfoIndex;
            }
            
            coordsPairInfoIndex++;
        }
    }

    printf("\n(%d,%d) and ",
            coordsPairinfo[maxDistanceCoordsPairInfoIndex].coords1.x,
            coordsPairinfo[maxDistanceCoordsPairInfoIndex].coords1.y);
    printf("(%d,%d)\n",
            coordsPairinfo[maxDistanceCoordsPairInfoIndex].coords2.x,
            coordsPairinfo[maxDistanceCoordsPairInfoIndex].coords2.y);
    printf("have a max distance of %lf",
            coordsPairinfo[maxDistanceCoordsPairInfoIndex].distance);
}