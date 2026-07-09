# Class containing Pascal's Triangle generation logic
class Solution:
    # Function to generate Pascal's Triangle up to numRows
    def generate(self, numRows):
        # Result list to hold all rows
        triangle = []

        # Loop for each row
        for i in range(numRows):
            # Create a row with size (i+1) and initialize all elements to 1
            row = [1] * (i + 1)

            # Fill elements from index 1 to i-1 (middle values)
            for j in range(1, i):
                # Each element = sum of two elements above it
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]

            # Add current row to the triangle
            triangle.append(row)

        return triangle


if __name__ == "__main__":
    obj = Solution()
    n = 5

    # Generate and print Pascal's Triangle
    result = obj.generate(n)
    for row in result:
        print(" ".join(map(str, row)))