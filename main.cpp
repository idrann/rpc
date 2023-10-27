#include <iostream>
#include <fstream>
#include "Person.pb.h"
#include "google/protobuf/io/zero_copy_stream_impl.h"
#include "google/protobuf/text_format.h"
 
 
using namespace test;
int main(){
  Person p;
  p.set_name("idarnn");
  p.set_id(97);
  p.set_email("a.iabc.com");
 
  //------------------将pb二进制信息保存到字符串
  std::string str;
  p.SerializeToString(&str);
  std::cout<<"str.size"<<str.size()<< " " <<str<<std::endl;  
 
  //------------------将pb文本信息写入文件
  std::ofstream fw; 
  fw.open("./Person.txt", std::ios::out | std::ios::binary);
  google::protobuf::io::OstreamOutputStream *output = new google::protobuf::io::OstreamOutputStream(&fw);
  google::protobuf::TextFormat::Print(p, output);
 
  delete output;
  fw.close();
 
  //---------------------将pb文本信息保存到字符串
  std::string str1;
  google::protobuf::TextFormat::PrintToString(p, &str1);
  std::cout<<"str1: ["<<str1<<"]"<<std::endl;
 
  //---------------------反序列化
  Person p1;
  p1.ParseFromString(str);
  std::cout<<"str.size"<<str.size()<<"name:"<<p1.name()<<",email:"<<p1.email()<<",id:"<<p1.id()<<std::endl;
  std::cout<<"---------------"<<endl;
  return 0;
}