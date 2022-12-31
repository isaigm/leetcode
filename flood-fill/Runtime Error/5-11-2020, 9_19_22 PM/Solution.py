// https://leetcode.com/problems/flood-fill

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        rows = len(image)
        cols = len(image[0])
        color = image[sr][sc]
        def fill(x : int, y: int):
            if image[y][x] == color:
                image[y][x] = newColor
                coords = [(x, y + 1), (x, y - 1), (x + 1, y), (x - 1, y)]
                """            (x, y-1) 
                (x - 1, sc)   (x, y) (x + 1, sc)
                            (x, y+1)
                """
                for px, py in coords:
                    if px >= 0 and px < cols and py >= 0 and py < rows:
                            fill(px, py)
        fill(sc, sr)
        return image