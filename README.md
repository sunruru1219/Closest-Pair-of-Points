# Closest-Pair-of-Points
Implemented a divide-and-conquer algorithm to find the closest pair of points in a 2D plane

## Overview

A C++ implementation of the closest pair of points problem in a 2D plane. Given a set of points, the program calculates the minimum Euclidean distance between any two points.

## Algorithm

The program uses a divide-and-conquer approach:

Divides the points into two halves based on their x-coordinates.

Recursively finds the minimum distance in each half.

Examines points near the dividing line to find a potentially smaller distance.

## Input Format

The first line contains an integer T, the number of test cases.

For each test case:

An integer n, the number of points.

n pairs of coordinates (x, y).

## Output

For each test case, outputs the minimum Euclidean distance between two points.

## Requirements

C++ compiler

Standard C++ libraries
