def calPoints(operations):
    """
    NOTE: The logic of modifying 'operations' while iterating 
    makes this function unstable and often incorrect.
    """
    result = 0
    # Copy the list for safe iteration, but the index lookups will still target the original 'operations'
    operations_copy = operations[:] 
    
    for num in operations_copy: 
        try:
            # Finding the index of 'num' in the *modified* list is the core instability
            index = operations.index(num) 
        except ValueError:
            # Item was already deleted or replaced
            continue
            
        if num == 'C':
            if index > 0:
                del operations[index-1: index+1]
        elif num == 'D':
            if index > 0:
                # Retain user's logic: this can lead to string multiplication (e.g., '5'*2 = '55')
                operations[index] = operations[index-1] * 2 
        elif num == '+':
            if index > 1:
                # Retain user's logic: this can lead to string concatenation (e.g., '5'+'10' = '510')
                operations[index] = operations[index-2] + operations[index-1]
        else:
            operations[index] = int(num)
        
    # Final summation loop as written by the user
    for x in operations:
        try:
            # Convert to int to sum
            result += int(x)
        except ValueError:
            # Handles errors if command strings remain
            pass 

    return result

# calPoints([["5","2","C","D","+"]])

def run_calPoints_tests():
    print("--- Running Tests for calPoints ---")

    # TEST CASE 1: Simple list that SHOULD execute cleanly
    input_1 = ["10", "20", "30"]
    # Expected result: Sum of 10 + 20 + 30 = 60
    expected_1 = 60
    actual_1 = calPoints(input_1)
    # The f-string is the error message if the test fails
    assert actual_1 == expected_1, f"Test 1 Failed: Expected {expected_1}, Got {actual_1}"
    print(f"Test 1 Passed. Input: {input_1}")

    # TEST CASE 2: Input that will expose the string manipulation flaw
    input_2 = ["5", "2", "D"]
    # Flawed internal logic: operations becomes [5, 2, '4'] then final sum = 11. (Correct is 14)
    expected_2 = 11 
    actual_2 = calPoints(input_2)
    assert actual_2 == expected_2, f"Test 2 Failed: Expected {expected_2}, Got {actual_2}"
    print(f"Test 2 Passed. Input: {input_2}")
    
    # TEST CASE 3: Input that will expose the index/deletion flaw
    input_3 = ["10", "C", "5"]
    # Flawed internal logic: 10 and C are deleted. operations becomes [5]. Final sum = 5.
    expected_3 = 5 
    actual_3 = calPoints(input_3)
    assert actual_3 == expected_3, f"Test 3 Failed: Expected {expected_3}, Got {actual_3}"
    print(f"Test 3 Passed. Input: {input_3}")

    print("\n✅ All assertions complete. Failures indicate code did not produce expected output.")

# Execute the test function
run_calPoints_tests()