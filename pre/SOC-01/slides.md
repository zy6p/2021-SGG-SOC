---
# try also 'default' to start simple
theme: seriph
# random image from a curated Unsplash collection by Anthony
# like them? see https://unsplash.com/collections/94734566/slidev
background: https://source.unsplash.com/collection/94734566/1920x1080
# apply any windi css classes to the current slide
class: 'text-center'
# https://sli.dev/custom/highlighters.html
highlighter: shiki
# some information about the slides, markdown enabled
info: |
  ## Slidev Starter Template
  Presentation slides for developers.

  Learn more at [Sli.dev](https://sli.dev)
---

# 2021 SGG SOC

2021 SGG Summer of code
测绘学院暑期 C++ 编程学校

<div class="pt-12">
  <span @click="$slidev.nav.next" class="px-2 py-1 rounded cursor-pointer" hover="bg-white bg-opacity-10">
    开始 <carbon:arrow-right class="inline"/>
  </span>
</div>

<br>
2021.07.14
王知远

<div class="abs-br m-6 flex gap-2">
  <button @click="$slidev.nav.openInEditor()" title="Open in Editor" class="text-xl icon-btn opacity-50 !border-none !hover:text-white">
    <carbon:edit />
  </button>
  <a href="https://github.com/zy6p/2021-SGG-SOC" target="_blank" alt="GitHub"
    class="text-xl icon-btn opacity-50 !border-none !hover:text-white">
    <carbon-logo-github />
  </a>
</div>


<!--
The last comment block of each slide will be treated as slide notes. It will be visible and editable in Presenter Mode along with the slide. [Read more in the docs](https://sli.dev/guide/syntax.html#notes)
-->

---

# Why SOC?

- 📝 **注重编程** - 测绘学院很注重编程，几乎每一门专业课都会设置编程大作业
- 🎨 **课程所限** - 大一上即开设 C/C++ 程序设计，但之后仅一门网络程序设计编程课
- 🧑‍💻 **专业需求** - 专业课大作业多为计算密集型，缺乏数据结构与算法会造成计算低效
- 🤹 **能力需求** - 程序员必备技能
- 🎥 **夏令营/考研重点** - 夏令营会重点考察项目经验以及编程能力

<br>
<br>

# Why C++?

- 📤 **高效** - 计算密集型程序适合 C/C++
- 🛠 **开源** - Matlab 容易被卡脖子

<!--
专业课编程大作业多数是要求 C++ 完成，而且所学内容也为 C/C++。
在测绘领域，C++ 是主流语言。
-->

<style>
h1 {
  background-color: #2B90B6;
  background-image: linear-gradient(45deg, #4EC5D4 10%, #146b8c 20%);
  background-size: 100%;
  -webkit-background-clip: text;
  -moz-background-clip: text;
  -webkit-text-fill-color: transparent; 
  -moz-text-fill-color: transparent;
}
</style>

---

# GeoHash

一种地址编码，能把二维的经纬度编码成一维的字符串

[在线体验地址：http://geohash.co/](http://geohash.co/)

|      |        |       |                         |
| ---- | ------ | ----- | ----------------------- |
| 城市 | 经度   | 纬度  | Hash                    |
| 武汉 | 114.31 | 30.52 | <kbd>wt3m95ypbh3g</kbd> |
| 珠海 | 113.52 | 22.30 | <kbd>webwz5wdztr1</kbd> |
| 上海 | 121.48 | 31.22 | <kbd>wtw3s77j9jv6</kbd> |

---

# 原理

<br>

## 计算机基础

1. 内存结构
2. int, float 等位结构
3. 进制

<br>

## 算法原理

1. 二分法
2. 位操作

---

<img
  src="https://geo.hotdry.top:18100/dl/img/world-hash.png"
/>

---

<img
  src="https://geo.hotdry.top:18100/dl/img/ellipsoid.png"
/>

