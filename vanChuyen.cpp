#include <iostream>
#include <vector>

class NoiGiao
{
public:
  NoiGiao() = default;
  NoiGiao(int prices)
  {
    contain = {};
    price = prices;
  }

  int getPrice() const { return price; }

  void receiveProduct(int product)
  {
    contain.push_back(product);
  }

  void printData()
  {
    std::cout << "Đã giao " << '\n';
    for (int data : contain)
    {
      std::cout << data << '\n';
    }
    std::cout << "Giá giao " << price << '\n';
  }

private:
  std::vector<int> contain{};
  int price{};
};

class Product
{
public:
  Product(std::vector<int> product, NoiGiao &company, std::vector<int> temp)
      : productList{product}, parner{company}, tempContainer{temp}
  {
  }

  int getInventoryNumber() const { return productList.size(); }

  void putInBox()
  {
    if (!productList.empty())
    {
      int product = productList.back();
      productList.pop_back();
      tempContainer.push_back(product);
    }
  }

  void deliveryProduct()
  {
    if (!tempContainer.empty())
    {
      int product = tempContainer.back();
      tempContainer.pop_back();
      parner.receiveProduct(product);
    }
  }

private:
  std::vector<int> productList{};
  NoiGiao &parner;
  std::vector<int> tempContainer{};
};

void moveProduct(Product &product)
{
  if (product.getInventoryNumber() == 0)
  {
    return;
  }

  product.putInBox();
  moveProduct(product);

  product.deliveryProduct();
}

int main()
{
  NoiGiao partner(150);
  Product item{{9, 8, 7, 6, 5, 4}, partner, {}};
  moveProduct(item);
  partner.printData(); // In ra giá trị sau khi đã giao hàng

  return 0;
}
