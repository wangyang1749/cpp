template < typename T >
void f( T s ){
  std::cout << s << '\n';
}
template void f<double>(double); 
template void f<>(char);    // 实例化 f<char>(char) ，推导出模板实参
template void f(int);        // 实例化 f<int>(int) ，推导出模板实参
// 实例化，编译器生成代码
//  void f(double s) {   // T: double
//      std::cout << s << '\n';
//  }
