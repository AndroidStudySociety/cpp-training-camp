//
// Created by Jesson on 2019-11-24.
//

#ifndef C_DEMO_FILE_OPERATE_H
#define C_DEMO_FILE_OPERATE_H


#include <stdio.h>
#include <stddef.h>
//熟悉感觉 1.基本理论 2.我的代码  3.基础的代码 （刷算法）

//定义一些方法 对文件的操作、bitmap的处理

/* get bytes of the file.
 *
 * @param filename Name of the file.
 * @return bytes of filename.
 */
long length(const char *filename);

/* Read file: Text and Line mode.
 *
 * @param filename Name of the file.
 * @return bytes of filename.
 */
int read_by_text_line(const char *filename);

/* Read file: Text and Block mode.
 *
 * @param filename Name of the file.
 * @return bytes of filename.
 */
int read_by_text_block(const char *filename);

/* Read file: Binary and Line mode.
 *
 * @param filename Name of the file.
 * @return bytes of filename.
 */
int read_by_binary_line(const char *filename);

/* Read file: Binary and Block mode.
 *
 * @param filename Name of the file.
 * @return bytes of filename.
 */
int read_by_binary_block(const char *filename);

/* Write file: Text and Line mode.
 *
 * @param filename Name of the file.
 * @return bytes of filename.
 */
int write_by_text_line(const char *filename);

/* Write file: Text and Block mode.
 *
 * @param filename Name of the file.
 * @return bytes of filename.
 */
int write_by_text_block(const char *filename);

/* Write file: Binary and Line mode.
 *
 * @param filename Name of the file.
 * @return bytes of filename.
 */
int write_by_binary_line(const char *filename);

/* Write file: Binary and Block mode.
 *
 * @param filename Name of the file.
 * @return bytes of filename.
 */
int write_by_binary_block(const char *filename);

/* Parameter input by stdin(string):
 *
 * @param param[] Save parameters, coming-and-out.
 * @param len Total length of parameters.
 * @return bytes of filename.
 */
int parameter_input(char *param[], size_t len);

#endif //C_DEMO_FILE_OPERATE_H
