<a name="readme-top"></a>

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/duckmaniac/simple-calculator">
    <img src="assets/icon.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Simple GUI Calculator</h3>

  <p align="center">
    A lightweight and intuitive calculator application built with C++ and powered by the SFML library.
    <br />
    Perform basic arithmetic operations with a sleek, user-friendly interface.
    <br />
    <a href="https://github.com/duckmaniac/simple-calculator/issues">Report Bug</a>
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project

<a href="https://github.com/duckmaniac/simple-calculator">
  <img src="assets/demo.gif" alt="Demonstration" width="300px">
</a>

Here's my first attempt at a C++ GUI project: a straightforward calculator using the SFML library. This project was a big step for me. I learned a lot, and some of its code even became the basis for my own small game engine. I hope it inspires others to start their projects too 🚀

Features:
* Basic arithmetic operations: addition, subtraction, multiplication, division
* Keyboard and mouse input support
* Clear and responsive UI

<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

* [![C++][cpp]][cpp-url]
* [![CMake][cmake]][cmake-url]
* [![Boost][boost]][boost-url]
* [![SFML][sfml]][sfml-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

Before you start your calculating journey, ensure:

* You have a CMake to build a project.
* The Boost 1.83.0 and SFML 2.6.0 library is set up and ready.
* In order to run this code, you will need a Windows operating system.

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/duckmaniac/simple-calculator.git
   ```
2. Navigate to project's root directory
   ```sh
   cd "path to dowloaded repo"
   ```
3. Set up path to libraries in CMakeLists.txt
   ```cmake
   set(CPP_LIBRARIES_DIR "path to libraries")
   set(SFML_DIR "${CPP_LIBRARIES_DIR}/SFML-2.6.0/lib/cmake/SFML")
   set(BOOST_ROOT "${CPP_LIBRARIES_DIR}/Boost/boost_1_83_0")
   ```
4. Run the configuration command
   ```sh
   cmake .
   ```
5. Build the project
   ```sh
   cmake --build .
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## License
Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Dmitrii Tarbaev - dmitry.tarbaev@gmail.com

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [SFML Library](https://www.sfml-dev.org/): made it easier to create this project
  
<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
[cpp]: https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white
[cmake]: https://img.shields.io/static/v1?style=for-the-badge&message=CMake&color=064F8C&logo=CMake&logoColor=FFFFFF&label=
[boost]: https://img.shields.io/badge/Boost-%2300599C.svg?style=for-the-badge&logoColor=white
[sfml]: https://img.shields.io/static/v1?style=for-the-badge&message=SFML&color=222222&logo=SFML&logoColor=8CC445&label=
[cpp-url]: https://cplusplus.com/
[cmake-url]: https://cmake.org/
[boost-url]: https://www.boost.org/
[sfml-url]: https://www.sfml-dev.org/
