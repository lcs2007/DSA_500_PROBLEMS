# Bài tập về nhà tuần 7 - Cấu trúc dữ liệu Mảng (Array)

Kho lưu trữ này bao gồm mã nguồn cài đặt 10 bài tập giải thuật xử lý trên cấu trúc dữ liệu mảng bằng ngôn ngữ C, kèm theo mô tả giải thuật và bộ dữ liệu kiểm thử chi tiết.

---

## Bài 1: Tìm cặp số có tổng bằng một giá trị cho trước (Find pair with given sum in an array)
- **File mã nguồn:** `problem_1.c`
- **Mô tả giải thuật:**
  Sử dụng phương pháp **Hai con trỏ (Two Pointers)** kết hợp với sắp xếp mảng:
  1. Sắp xếp mảng đầu vào theo thứ tự tăng dần bằng thuật toán Bubble Sort.
  2. Khởi tạo hai con trỏ: `left = 0` (đầu mảng) và `right = n - 1` (cuối mảng).
  3. Lặp khi `left < right`:
     - Tính tổng `currentSum = arr[left] + arr[right]`.
     - Nếu `currentSum == target`: In ra cặp số `(arr[left], arr[right])`, đánh dấu đã tìm thấy (`found = 1`), đồng thời dịch chuyển cả hai con trỏ (`left++`, `right--`) để tìm tiếp các cặp khác (nếu có).
     - Nếu `currentSum < target`: Tăng `left` lên 1 để tăng giá trị tổng.
     - Nếu `currentSum > target`: Giảm `right` đi 1 để giảm giá trị tổng.
  4. **Độ phức tạp:** Thời gian $O(n^2)$ (do bước Bubble Sort; phần tìm kiếm hai con trỏ chỉ mất $O(n)$), Không gian $O(1)$.
- **Dữ liệu kiểm thử (Test cases):**
  - **Test case 1 (Có nhiều cặp thỏa mãn):**
    - Input: `n = 6`, `arr = [8, 7, 2, 5, 3, 1]`, `target = 10`
    - Output:
      ```text
      Pair found: (2, 8)
      Pair found: (3, 7)
      ```
  - **Test case 2 (Không có cặp nào thỏa mãn):**
    - Input: `n = 5`, `arr = [5, 2, 6, 8, 1]`, `target = 12`
    - Output: `Pair not found.`

---

## Bài 2 & 3: Kiểm tra và in ra tất cả các mảng con có tổng bằng 0 (Check & print all subarrays with 0 sum)
- **File mã nguồn:** `problem_2&3.c`
- **Mô tả giải thuật:**
  Sử dụng phương pháp **Duyệt vét cạn theo cửa sổ độ dài (Brute-force sliding length)**:
  1. Sử dụng vòng lặp ngoài duyệt qua các kích thước mảng con `i` có thể có (từ `2` đến `n`).
  2. Sử dụng vòng lặp trong duyệt qua vị trí bắt đầu `j` của mảng con (từ `0` đến `n - i`).
  3. Tại mỗi vị trí `j`, truyền con trỏ `arr + j` và độ dài `i` vào hàm `sumArray` để tính tổng các phần tử liên tiếp của mảng con đó.
  4. Nếu tổng bằng `0`, thông báo tồn tại mảng con có tổng bằng 0 và gọi hàm `printArray(arr + j, i)` để in mảng con đó ra màn hình.
  5. **Độ phức tạp:** Thời gian $O(n^3)$, Không gian $O(1)$.
- **Dữ liệu kiểm thử (Test cases):**
  - **Test case 1 (Tồn tại nhiều mảng con có tổng bằng 0):**
    - Input: `n = 6`, `arr = [4, 2, -3, -1, 0, 4]`
    - Output:
      ```text
      The entered array is: [4, 2, -3, -1, 0, 4]
      Subarrays with zero-sum exists.
      The subarrays with a sum of 0 are: 
      [-3, -1, 0, 4]
      [2, -3, -1]
      [2, -3, -1, 0]
      ```
  - **Test case 2 (Không tồn tại mảng con có tổng bằng 0):**
    - Input: `n = 4`, `arr = [1, 2, 3, 4]`
    - Output:
      ```text
      The entered array is: [1, 2, 3, 4]
      No subarray with zero-sum found.
      ```

---

## Bài 4: Sắp xếp mảng nhị phân trong thời gian tuyến tính (Sort binary array in linear time)
- **File mã nguồn:** `problem_4.c`
- **Mô tả giải thuật:**
  Sử dụng phương pháp **Đếm tần suất (Counting)**:
  1. Duyệt qua toàn bộ mảng một lần để đếm tổng số lượng phần tử có giá trị bằng `0` (lưu vào biến `count0`).
  2. Dùng vòng lặp gán giá trị `0` cho `count0` phần tử đầu tiên của mảng (từ chỉ số `0` đến `count0 - 1`).
  3. Dùng vòng lặp gán giá trị `1` cho toàn bộ các phần tử còn lại (từ chỉ số `count0` đến `n - 1`).
  4. **Độ phức tạp:** Thời gian $O(n)$ (duyệt mảng 2 lần), Không gian $O(1)$.
- **Dữ liệu kiểm thử (Test cases):**
  - **Test case 1 (Mảng gán sẵn trong chương trình):**
    - Input: `array = {0, 1, 0, 1, 1, 0, 0, 1}`
    - Output:
      ```text
      Original binary array: {0, 1, 0, 1, 1, 0, 0, 1}
      Sorted binary array: {0, 0, 0, 0, 1, 1, 1, 1}
      ```
  - **Test case 2 (Mảng chỉ toàn một giá trị hoặc đã sắp xếp):**
    - Input: `array = {1, 1, 1, 0, 0}`
    - Output:
      ```text
      Original binary array: {1, 1, 1, 0, 0}
      Sorted binary array: {0, 0, 1, 1, 1}
      ```

---

## Bài 5: Tìm phần tử bị lặp trong mảng có giới hạn giá trị (Find duplicate element in a limited range array)
- **File mã nguồn:** `problem_5.c`
- **Mô tả giải thuật:**
  Sử dụng thuật toán **Tìm chu trình của Floyd (Floyd's Tortoise and Hare / Cycle Detection)**:
  - **Cơ sở lý thuyết:** Mảng có `n` phần tử với các giá trị thuộc đoạn `[1, n - 1]`. Nếu coi mỗi chỉ số mảng là một nút và giá trị `arr[i]` là con trỏ trỏ tới nút tiếp theo, việc tồn tại phần tử trùng lặp sẽ tạo ra một chu trình (vòng lặp) với điểm bắt đầu chu trình chính là phần tử bị lặp.
  - **Giai đoạn 1 (Phát hiện chu trình):** Khởi tạo 2 con trỏ `slow = arr[0]` và `fast = arr[0]`. Cho `slow` đi 1 bước (`slow = arr[slow]`) và `fast` đi 2 bước (`fast = arr[arr[fast]]`) cho đến khi chúng gặp nhau bên trong chu trình (`slow == fast`).
  - **Giai đoạn 2 (Tìm điểm bắt đầu chu trình):** Đưa `slow` về lại vị trí đầu (`arr[0]`), giữ nguyên vị trí của `fast`. Cho cả hai cùng di chuyển từng bước một (`slow = arr[slow]`, `fast = arr[fast]`). Vị trí chúng gặp lại nhau chính là giá trị phần tử bị lặp.
  - **Độ phức tạp:** Thời gian $O(n)$, Không gian $O(1)$.
- **Dữ liệu kiểm thử (Test cases):**
  - **Test case 1 (Lặp ở giữa mảng):**
    - Input: `n = 5`, `array = {1, 2, 3, 4, 4}`
    - Output:
      ```text
      The input array is: {1, 2, 3, 4, 4}
      The duplicate element is: 4
      ```
  - **Test case 2 (Phần tử lặp nằm cách xa nhau):**
    - Input: `n = 6`, `array = {1, 3, 4, 2, 5, 2}`
    - Output:
      ```text
      The input array is: {1, 3, 4, 2, 5, 2}
      The duplicate element is: 2
      ```

---

## Bài 7: Tìm tất cả mảng con có tổng cho trước và tìm mảng con dài nhất (Find maximum length subarray having a given sum)
- **File mã nguồn:** `problem_7.c`
- **Mô tả giải thuật:**
  Sử dụng phương pháp **Duyệt vét cạn mọi mảng con (Brute-force)** kết hợp biến theo dõi độ dài cực đại:
  1. Khởi tạo `maxLength = 0`, `maxSubarrayStart = -1` để lưu thông tin của mảng con dài nhất.
  2. Dùng hai vòng lặp lồng nhau: vòng ngoài cố định điểm đầu `i` (từ `0` đến `n - 1`), vòng trong dịch chuyển điểm cuối `j` (từ `i` đến `n - 1`).
  3. Tính tổng các phần tử của mảng con từ chỉ số `i` đến `j` (độ dài `j - i + 1`) thông qua hàm `sumArray(arr + i, j - i + 1)`.
  4. Nếu tổng bằng `targetSum`:
     - In mảng con hiện tại ra màn hình.
     - Kiểm tra nếu độ dài hiện tại `j - i + 1 > maxLength` thì cập nhật `maxLength = j - i + 1` và lưu lại vị trí bắt đầu `maxSubarrayStart = i`.
  5. Sau khi duyệt xong, nếu tìm thấy ít nhất một mảng con (`found == 1`), in ra mảng con dài nhất bắt đầu từ `arr + maxSubarrayStart` với kích thước `maxLength`.
  6. **Độ phức tạp:** Thời gian $O(n^3)$, Không gian $O(1)$.
- **Dữ liệu kiểm thử (Test cases):**
  - **Test case 1 (Có nhiều mảng con thỏa mãn với độ dài khác nhau):**
    - Input: `n = 7`, `arr = [5, 6, -5, 5, 3, 5, 3]`, `targetSum = 8`
    - Output:
      ```text
      The entered array is: [5, 6, -5, 5, 3, 5, 3]
      Subarrays with the given sum exist.
      The subarrays with a sum of 8 are: 
      [5, 3]
      [6, -5, 5, 3]
      [-5, 5, 3, 5]
      [3, 5]
      [5, 3]
      The longest subarray with the given sum is: [6, -5, 5, 3]
      ```
  - **Test case 2 (Không có mảng con nào thỏa mãn):**
    - Input: `n = 4`, `arr = [1, 2, 3, 4]`, `targetSum = 15`
    - Output:
      ```text
      The entered array is: [1, 2, 3, 4]
      No subarray with the given sum found.
      ```

---

## Bài 13: Tìm tích lớn nhất của hai số nguyên trong mảng (Find maximum product of two integers in an array)
- **File mã nguồn:** `problem_13.c`
- **Mô tả giải thuật:**
  Sử dụng phương pháp **Duyệt tuyến tính một lần (Single-pass Linear Scan)**:
  1. Kiểm tra điều kiện biên: nếu kích thước mảng `n < 2`, thông báo lỗi và kết thúc.
  2. Khởi tạo hai biến `max1` (số lớn nhất) và `max2` (số lớn thứ hai) bằng cách so sánh hai phần tử đầu tiên `arr[0]` và `arr[1]`.
  3. Duyệt mảng từ chỉ số `i = 2` đến `n - 1`:
     - Nếu `arr[i] > max1`: cập nhật `max2 = max1` và `max1 = arr[i]`.
     - Ngược lại, nếu `arr[i] > max2`: cập nhật `max2 = arr[i]`.
  4. Trả về kết quả là tích `max1 * max2`.
  5. **Độ phức tạp:** Thời gian $O(n)$, Không gian $O(1)$.
- **Dữ liệu kiểm thử (Test cases):**
  - **Test case 1 (Mảng các số nguyên dương):**
    - Input: `n = 5`, `array = {1, 7, 3, 4, 9}`
    - Output:
      ```text
      The input array is: {1, 7, 3, 4, 9}
      The maximum product of two integers in the array is: 63
      ```
  - **Test case 2 (Mảng có phần tử lớn nhất lặp lại):**
    - Input: `n = 4`, `array = {8, 2, 8, 5}`
    - Output:
      ```text
      The input array is: {8, 2, 8, 5}
      The maximum product of two integers in the array is: 64
      ```

---

## Bài 16: Tìm chỉ số cân bằng của mảng (Find equilibrium index of an array)
- **File mã nguồn:** `problem_16.c`
- **Mô tả giải thuật:**
  Sử dụng phương pháp **Tổng tiền tố / Tổng phần bù (Prefix Sum)**:
  - *Định nghĩa:* Chỉ số cân bằng `i` là vị trí mà tổng các phần tử bên trái nó (`arr[0 ... i-1]`) bằng tổng các phần tử bên phải nó (`arr[i+1 ... n-1]`).
  1. Duyệt mảng lần thứ nhất để tính tổng toàn bộ các phần tử trong mảng và lưu vào `totalSum`.
  2. Khởi tạo tổng bên trái `leftSum = 0`.
  3. Duyệt mảng lần thứ hai tại mỗi chỉ số `i`:
     - Trừ `arr[i]` khỏi `totalSum` (`totalSum -= arr[i]`). Lúc này `totalSum` đóng vai trò là tổng của toàn bộ các phần tử nằm bên phải chỉ số `i`.
     - So sánh nếu `leftSum == totalSum` thì in ra vị trí cân bằng `i` và đánh dấu `found = 1`.
     - Cộng dồn `arr[i]` vào `leftSum` (`leftSum += arr[i]`) trước khi sang bước lặp tiếp theo.
  4. **Độ phức tạp:** Thời gian $O(n)$, Không gian $O(1)$.
- **Dữ liệu kiểm thử (Test cases):**
  - **Test case 1 (Có nhiều vị trí cân bằng):**
    - Input: `n = 8`, `arr = {0, -3, 5, -4, -2, 3, 1, 0}`
    - Output:
      ```text
      The input array is: {0, -3, 5, -4, -2, 3, 1, 0}
      Equilibrium index found at position: 0
      Equilibrium index found at position: 3
      Equilibrium index found at position: 7
      ```
  - **Test case 2 (Không có vị trí cân bằng):**
    - Input: `n = 4`, `arr = {1, 2, 3, 4}`
    - Output:
      ```text
      The input array is: {1, 2, 3, 4}
      No equilibrium index found in the array.
      ```

---

## Bài 19: Thay thế mỗi phần tử bằng tích của tất cả các phần tử khác mà không dùng phép chia (Replace every element with product of every other element)
- **File mã nguồn:** `problem_19.c`
- **Mô tả giải thuật:**
  Sử dụng phương pháp **Nhân vét cạn với mảng phụ (Brute-force with auxiliary array)**:
  1. Khởi tạo mảng phụ `product[n]` có cùng kích thước với mảng ban đầu để lưu kết quả tạm thời, tránh việc ghi đè làm mất giá trị gốc trong quá trình tính toán.
  2. Sử dụng vòng lặp ngoài duyệt qua từng vị trí `i` (từ `0` đến `n - 1`):
     - Gán `product[i] = 1`.
     - Sử dụng vòng lặp trong duyệt qua từng vị trí `j` (từ `0` đến `n - 1`). Nếu `i != j`, nhân dồn `product[i] *= arr[j]`.
  3. Sao chép toàn bộ giá trị từ mảng `product` sang mảng `arr` ban đầu và in kết quả.
  4. **Độ phức tạp:** Thời gian $O(n^2)$, Không gian $O(n)$.
- **Dữ liệu kiểm thử (Test cases):**
  - **Test case 1 (Mảng các số nguyên dương):**
    - Input: `n = 5`, `arr = [1, 2, 3, 4, 5]`
    - Output:
      ```text
      The input array is: [1, 2, 3, 4, 5]
      The modified array is: [120, 60, 40, 30, 24]
      ```
  - **Test case 2 (Mảng có chứa phần tử 0):**
    - Input: `n = 4`, `arr = [5, 3, 0, 2]`
    - Output:
      ```text
      The input array is: [5, 3, 0, 2]
      The modified array is: [0, 0, 30, 0]
      ```

---

## Bài 21: Tìm hiệu lớn nhất giữa hai phần tử sao cho số nhỏ hơn đứng trước số lớn hơn (Find maximum difference between two elements)
- **File mã nguồn:** `problem_21.c`
- **Mô tả giải thuật:**
  Sử dụng phương pháp **Duyệt tuyến tính kết hợp theo dõi giá trị nhỏ nhất (Single-pass tracking minimum)**:
  1. Khởi tạo phần tử nhỏ nhất từng gặp `minElement = arr[0]`, phần tử lớn nhất tạo hiệu cực đại `maxElement = arr[1]`, và hiệu lớn nhất `maxDiff = arr[1] - arr[0]`.
  2. Duyệt mảng từ chỉ số `i = 1` đến `n - 1`:
     - Nếu hiệu giữa phần tử hiện tại và phần tử nhỏ nhất phía trước lớn hơn kỷ lục hiện có (`arr[i] - minElement > maxDiff`), cập nhật `maxDiff = arr[i] - minElement` và lưu lại `maxElement = arr[i]`.
     - Nếu phần tử hiện tại nhỏ hơn `minElement` (`arr[i] < minElement`), cập nhật `minElement = arr[i]` để làm mốc cho các phần tử phía sau.
  3. In ra hiệu lớn nhất `maxDiff` và cặp phần tử thỏa mãn điều kiện.
  4. **Độ phức tạp:** Thời gian $O(n)$, Không gian $O(1)$.
- **Dữ liệu kiểm thử (Test cases):**
  - **Test case 1 (Trường hợp chuẩn):**
    - Input: `n = 7`, `arr = {2, 7, 9, 5, 1, 3, 5}`
    - Output:
      ```text
      The input array is: {2, 7, 9, 5, 1, 3, 5}
      The maximum difference between two elements in the array is: 7
      The pair that satisfies this condition is: (2, 9)
      ```
  - **Test case 2 (Mảng tăng dần đều):**
    - Input: `n = 5`, `arr = {1, 4, 8, 12, 20}`
    - Output:
      ```text
      The input array is: {1, 4, 8, 12, 20}
      The maximum difference between two elements in the array is: 19
      The pair that satisfies this condition is: (1, 20)
      ```