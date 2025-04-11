// hàm tính giai thừa
int factorial(int n)
{
	if (n < 1) return 0; // điều kiện n không hợp lệ
	if (n == 1) return 1; // diều kiện dừng
	return n * factorial(n - 1); // đệ quy n * giai thừ của n - 1
}
