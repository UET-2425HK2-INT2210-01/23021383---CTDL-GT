// hàm đảo ngược số
int dao_nguoc(int n, int x = 0)
{
	if (n == 0) return x; // điều kiện dừng
	return dao_nguoc(n / 10, x * 10 + n % 10); // đệ quy với phần dư của n / 10 và x * 10 + n % 10
}
