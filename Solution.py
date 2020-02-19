class Solution(object):

    def __init__(self, file_path):
        """
        Reads input file and creates variables.
        """
        
        line_generator = (line for line in open(file_path))
        hub_info = next(line_generator).split()
        self.max_slices = int(hub_info[0])
        self.total_pizzas = int(hub_info[1])
        self.pizza_menu = [int(x) for x in next(line_generator).split()]
        self.greedy_sum = 0
        self.greedy_combo = []
        
    def make_pizza_order(self, desired_pizza_combo):
        """
        Writes the output of find_subset() to file.
        """
        
        order_length = str(len(desired_pizza_combo))
        file = open('hub_pizza_order.txt','w')
        
        file.write(order_length + '\n')
        
        for pizza in desired_pizza_combo:
            file.write(str(pizza) + " ")
            
        return "The hubs pizza order is ready"
        
    def find_subset(self):
        """
        Bottom up matrix traversal or greedy algo to find
        a subset nearest to the desired sum.
        """

        # Greedy algo for large datasets
        if self.max_slices > 10000 and self.total_pizzas > 1000:
            index_count = 0
            for pizza in self.pizza_menu:
                current_sum = self.greedy_sum + pizza
                
                if current_sum > self.max_slices:
                    continue
                else:
                    self.greedy_combo.append(index_count)
                    self.greedy_sum += pizza

                if self.greedy_sum == self.max_slices:
                    return self.make_pizza_order(self.greedy_combo)
                
                index_count += 1
                
            return self.make_pizza_order(self.greedy_combo)
        
        # Bottom-up algo for smaller datasets        
        else:
            # Bounds for matrix construction
            row = self.total_pizzas
            col = self.max_slices + 1

            # Initialize matrix of zeros
            pizza_matrix = [[0] * col for i in range(row)]
            
            for i in range(row):
                for j in range(1, col):
                    if i == 0:
                        if j >= self.pizza_menu[i]:
                            pizza_matrix[i][j] = self.pizza_menu[i]
                        else:
                            continue
                    else:
                        if j - self.pizza_menu[i] >= 0:
                            pizza_matrix[i][j] = max(pizza_matrix[i - 1][j], (self.pizza_menu[i] + pizza_matrix[i - 1][j - self.pizza_menu[i]]))
                            
                        elif j >= self.pizza_menu[i]:
                            pizza_matrix[i][j] = max(pizza_matrix[i - 1][j], self.pizza_menu[i])
                            
                        else:
                            pizza_matrix[i][j] = pizza_matrix[i - 1][j]

            # Find out which Numbers should be in the subset
            # give from index 0
            row -= 1
            col -= 1
            sum_subset = []
            index_subset = []

            # get the subset
            while col >= 0 and row >= 0 and self.max_slices > 0:
                # First Row
                if (row == 0):
                    sum_subset.append(self.pizza_menu[row])
                    index_subset.append(row)
                    break

                # Check bottom right value and traverse for subset
                if (pizza_matrix[row][col] != pizza_matrix[row - 1][col]):
                    sum_subset.append(self.pizza_menu[row])
                    index_subset.append(row)
                    self.max_slices -= self.pizza_menu[row]
                    col -= self.pizza_menu[row]
                    row -= 1
                else:
                    row -= 1

            return self.make_pizza_order(index_subset)

# Test Driver
answer = Solution('e_also_big.in')
print(answer.find_subset())
