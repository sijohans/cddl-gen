/*
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <ztest.h>
#include "pet_encode.h"
// #include "serial_recovery.h"

uint8_t serial_rec_input1[] = {
	/* "data" */
	0xa5, 0x64, 0x64, 0x61, 0x74, 0x61, 0x59, 0x01,
	0x29, 0x3d, 0xb8, 0xf3, 0x96, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x02, 0x00, 0x00, 0xdc, 0x37, 0x00,

	/* 280 zeros */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, 0x00, /* "image" */ 0x65, 0x69, 0x6d, 0x61, 0x67, 0x65,
	0x00, /* "len" */ 0x63, 0x6c, 0x65, 0x6e, 0x19, 0x3b, 0x2c,
	/* "off" */ 0x63, 0x6f, 0x66, 0x66, 0x00, /* "sha" */ 0x63, 0x73, 0x68,
	0x61, 0x58, 0x20, 0x12, 0x87, 0x4f, 0xfe, 0x60,
	0x5b, 0xe0, 0x63, 0x1a, 0x03, 0x5a, 0xa2, 0x11,
	0xb4, 0x3e, 0x0f, 0xb0, 0x20, 0x42, 0x0f, 0xc4,
	0x31, 0xa7, 0xf1, 0x1a, 0x6a, 0xd3, 0x44, 0x4c,
	0x71, 0x99, 0x75
};


uint8_t serial_rec_input2[] = {
	/* "data" */
	0xa5, 0x64, 0x64, 0x61, 0x74, 0x61, 0x59, 0x01,
	0x29, 0x3d, 0xb8, 0xf3, 0x96, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x02, 0x00, 0x00, 0x90, 0x2c, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01,

	/* 11 zeros */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00,

	/* 265 0xffs */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff,

	/* "image" */
	0x65, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x00, /* "len" */ 0x63,
	0x6c, 0x65, 0x6e, 0x19, 0x2f, 0xe0, /* "off" */ 0x63, 0x6f,
	0x66, 0x66, 0x00, /* "sha" */ 0x63, 0x73, 0x68, 0x61, 0x58,
	0x20, 0x1d, 0x4f, 0x47, 0xe6, 0xdf, 0x78, 0xad,
	0x34, 0xe2, 0xd2, 0x8f, 0xc6, 0x7b, 0x3f, 0x26,
	0xff, 0x3c, 0x73, 0x44, 0x93, 0x13, 0x32, 0x7b,
	0x27, 0x15, 0xfa, 0x1d, 0x6e, 0x21, 0x82, 0xcb,
	0xfb
};

void test_pet(void)
{
	Pet_t pet = {
		._Pet_name_tstr = {{.value = "foo", .len = 3}, {.value = "bar", .len = 3}},
		._Pet_name_tstr_count = 2,
		._Pet_birthday = {.value = (uint8_t[]){1,2,3,4,5,6,7,8}, .len = 8},
		._Pet_species_dog = 2,
		._Pet_species_choice = _Pet_species_dog
	};
	uint8_t exp_output[] = {
#ifndef CDDL_CBOR_CANONICAL
		0x9f, 0x9f,
#else
		0x83, 0x82,
#endif
		0x63, 0x66, 0x6f, 0x6f, 0x63, 0x62, 0x61, 0x72,
#ifndef CDDL_CBOR_CANONICAL
		0xff,
#endif
		0x48, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x02,
#ifndef CDDL_CBOR_CANONICAL
		0xff
#endif
	};

	uint8_t output[25];
	size_t out_len;

	zassert_true(cbor_encode_Pet(output, sizeof(output), &pet, &out_len), "");

	zassert_equal(sizeof(exp_output), out_len, NULL);
	zassert_mem_equal(exp_output, output, sizeof(exp_output), NULL);
}

// void test_serial1(void)
// {
// 	Upload_t upload;
// 	bool ret = cbor_decode_Upload(serial_rec_input1,
// 			sizeof(serial_rec_input1), &upload);
// 	zassert_true(ret, "decoding failed.");

// 	zassert_equal(5, upload._Upload_members_count,
// 		"expect 5 members");
// 	zassert_equal(_Member_data, upload._Upload_members[0]
// 		._Member_choice, "expect data 1st");
// 	zassert_equal(_Member_image, upload._Upload_members[1]
// 		._Member_choice, "expect image 2nd");
// 	zassert_equal(_Member_len, upload._Upload_members[2]
// 		._Member_choice, "expect len 3rd");
// 	zassert_equal(_Member_off, upload._Upload_members[3]
// 		._Member_choice, "expect off 4th");
// 	zassert_equal(_Member_sha, upload._Upload_members[4]
// 		._Member_choice, "expect sha 5th");
// }

// void test_serial2(void)
// {
// 	Upload_t upload;
// 	bool ret = cbor_decode_Upload(serial_rec_input2,
// 			sizeof(serial_rec_input2), &upload);
// 	zassert_true(ret, "decoding failed.");

// 	zassert_equal(5, upload._Upload_members_count,
// 		"expect 5 members");
// 	zassert_equal(_Member_data, upload._Upload_members[0]
// 		._Member_choice, "expect data 1st");
// 	zassert_equal(_Member_image, upload._Upload_members[1]
// 		._Member_choice, "expect image 2nd");
// 	zassert_equal(_Member_len, upload._Upload_members[2]
// 		._Member_choice, "expect len 3rd");
// 	zassert_equal(_Member_off, upload._Upload_members[3]
// 		._Member_choice, "expect off 4th");
// 	zassert_equal(_Member_sha, upload._Upload_members[4]
// 		._Member_choice, "expect sha 5th");
// }

void test_main(void)
{
	ztest_test_suite(cbor_encode_test2,
			 ztest_unit_test(test_pet)
			//  ztest_unit_test(test_serial1),
			//  ztest_unit_test(test_serial2)
	);
	ztest_run_test_suite(cbor_encode_test2);
}
