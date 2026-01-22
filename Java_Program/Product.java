class ProductList {
	int product_code;;
	String product_name;
	double product_price;

	ProductList(int product_code, String product_name, double product_price) {
		this.product_code = product_code;
		this.product_name = product_name;
		this.product_price = product_price;
	}
}


class Product {
	public static  void main(String[] ar) {
		ProductList shampoo = new ProductList(01, "Shampoo", 28.98);
		ProductList shirt = new ProductList(02, "Shrit", 999.90);
		ProductList mobile = new ProductList(03, "Mobile", 17999);

		ProductList cheapestProduct;
		
		if(shampoo.product_price < shirt.product_price && shampoo.product_price < mobile.product_price)
			cheapestProduct = shampoo;
		else if(shirt.product_price < mobile.product_price && shirt.product_price < shampoo.product_price)
			cheapestProduct = shirt;
		else
			cheapestProduct = mobile;
			System.out.println("Cheapest Product Code : " + cheapestProduct.product_code + "\nCheapest Product is : " + cheapestProduct.product_name + "\nPrice $" + cheapestProduct.product_price);
		}
}
