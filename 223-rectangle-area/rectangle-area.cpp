class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int widthA = ax2 - ax1;
        int heightA = ay2 - ay1;
        int areaA = widthA * heightA;

        int widthB = bx2 - bx1;
        int heightB = by2 - by1;
        int areaB = widthB * heightB;

        int ans = areaA + areaB;

        int x1 = max(ax1, bx1);
        int x2 = min(ax2, bx2);
        int width = max(0, x2-x1);

        int y1 = max(ay1, by1);
        int y2 = min(ay2, by2);
        int height = max(0, y2 - y1);

        int area = width * height;
        ans = ans - area;

        return ans;
    }
};