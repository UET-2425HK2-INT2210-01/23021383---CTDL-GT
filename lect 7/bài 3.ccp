// hàm tính fibonacci
int fibonacci(int n)
{
	if (n <= 0) return 0; // điều kiện không hợp lệ
	if (n == 1) return 1; // điều kiện dừng
	return fibonacci(n - 1) + fibonacci(n - 2); // đệ quy theo công thức
}
