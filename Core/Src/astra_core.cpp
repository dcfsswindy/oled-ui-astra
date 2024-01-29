//
// Created by Fir on 2024/1/21.
//

//每个列表应该有 1. 文本（需要显示的内容） 2. 跳转向量表（对应1，每一行都要跳转到哪里）
//其中文本以string形式 向量表以vector形式 以类的形式整合在一起 编写相应的构造函数 调用构造函数即是新建一个页面
//通过最后一项跳转向量表可以判断其类型 比如跳转至下一页 或者返回上一级 或者是复选框 或者是弹窗 或者是侧边栏弹窗 等等
//做一个astra类作为总的框架 在ui命名空间里

//分为
//驱动层 - 界面层（包括各种列表 磁铁 复选框 侧边栏 弹窗等） - 处理层（各种坐标的变换等）

//传进去的有三个东西 第一个是文字（要显示的东西） 第二个是类别（普通列表 跳转列表 复选框） 第三个是特征向量（指向复选框和弹窗对应的参数 要跳转的地方等）

#include "vector"
#include "astra_core.h"

#include "string"

/**
 *     ·  ·     ·   ·
 *  ·   ·  ·  ·   ·
 * 循此苦旅，直抵群星。
 * ad astra per aspera.
 * ·   ·   ·      ·
 *   ·   ·    · ·   ·
 */

namespace astra {

/**
 * @brief preorder traversal to find certain page(node)
 *
 * @param _rootPage current page point
 * @param _lookingFor the page looking for
 * @return pointer of the page we looking for
 */
Page* Page::findPage(Page* _rootPage, const Page* _lookingFor) {  //NOLINT
  if (nullptr ==_rootPage) return nullptr;
  if (_rootPage == _lookingFor) return _rootPage;

  //search in all child page
  for (auto _childPage:_rootPage->childPage) {
    auto _result = findPage((Page*)_childPage, _lookingFor);
    if (_result != nullptr) return _result;
  }

  return nullptr;
}

/**
 * @brief init a new page and connect it to its parent page.
 *
 * @param _text the text of new page.
 * @param _parentPage the parent(previous) page of new page.
 */
Page::Page(std::vector<std::string> _text, Page *_parentPage) {
  //this->rootPage = nullptr;
  this->childPage = {};
  this->parentPage = _parentPage;
  _parentPage->childPage.push_back(this);   //connect this page to its parent page

  this->text = std::move(_text);
  this->select = 0;
  this->num = text.size();
}

Page::Page(std::vector<std::string> _text, std::vector<std::vector<uint8_t>> _pic) {
  //this->rootPage = this;
  this->childPage = {};
  this->parentPage = nullptr;

  this->text = std::move(_text);
  this->select = 0;
  this->pic = std::move(_pic);
  this->num = text.size();
}

/**
 * @brief add widget for certain item.
 * @todo waiting to be realized
 *
 * @param _page pointer to the page needs to add widget.
 * @param _text the item needs to add widget.
 * @param _widgetType 1: check box | 2: window | 3: side bar
 * @param _value the value widget will change.
 */
void Page::addWidget(Page *_page, const std::string& _text, uint8_t _widgetType, uint8_t &_value) {
  //_page->
}


/**
 * @brief init the framework
 */
void UIScheduler::init() {

}

/**
 * @brief start astra ui framework.
 *
 * @todo 找之前firmware的各种proc的共同点 转而使用指针等来实现
 * @param _root pointer to root node of page tree.
 */
void UIScheduler::astraKernelStart(Page *_root) {

}
}