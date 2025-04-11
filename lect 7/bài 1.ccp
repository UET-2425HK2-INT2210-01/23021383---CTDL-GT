// hàm tính tổng từ 1 đến n
int sum(int n)
{
	if (n < 1) return 0; // nếu n < 1 return 0
	if (n == 1) return 1; // điều kiện dừng
	return n + sum(n - 1); // đệ quy sum = n + sum(n - 1)
}
