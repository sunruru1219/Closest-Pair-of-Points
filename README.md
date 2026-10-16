# Closest Pairs of Points
This repository contains a C++ solution for the classic **Closest Pair of Points** problem,
implemented using the **Divide and Conquer** algorithm.

## Background
This project was originally developed as an assignment for the **Algorithms** course at **National Yang Ming Chiao Tung University (NYCU)** during the Fall 2023 semester.

## Overview

A C++ implementation of the closest pair of points problem in a 2D plane.
Given a set of points, the program calculates the minimum Euclidean distance between any two distinct points.

## Algorithm

The program uses a divide-and-conquer approach:

* **Divides:** Sort the points based on their x-coordinates and divide them into two equal halves.

* **Conquer:** Recursively find the minimum distance in each half.

* **Combine:** Examine points near the dividing line (the strip) to find a potentially smaller distance.

## Input Format

The first line contains an integer `T`, representing the number of test cases.

For each test case:

* An integer `n`, representing the number of points.

* `n` lines follow, each containing a pair of coordinates `(x, y)`.

## Output Format

For each testcase, outputs the minimum Euclidean distance between two points.

## Requirements

A C++ compiler supporting standard C++11 or higher
