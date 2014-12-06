//===--- RuntimeShims.h - Access to runtime facilities for the core -------===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//
//
//  Runtime functions and structures needed by the core stdlib are
//  declared here.
//
//===----------------------------------------------------------------------===//

#ifndef SWIFT_STDLIB_SHIMS_RUNTIMESHIMS_H
#define SWIFT_STDLIB_SHIMS_RUNTIMESHIMS_H

#include "SwiftStddef.h"
#include "SwiftStdint.h"

#ifdef __cplusplus
namespace swift { extern "C" {
#else
#define bool _Bool
#endif

/// Is this pointer a non-null unique reference to an object
/// that uses Swift reference counting?
bool _swift_isUniquelyReferencedNonObjC(const void *);

/// Is this non-null pointer a unique reference to an object
/// that uses Swift reference counting?
bool _swift_isUniquelyReferencedNonObjC_nonNull(const void *);

/// Is this non-null BridgeObject a unique reference to an object
/// that uses Swift reference counting?
bool _swift_isUniquelyReferencedNonObjC_nonNull_bridgeObject(
  __swift_uintptr_t bits);

/// Is this native Swift pointer a non-null unique reference to
/// an object?
bool _swift_isUniquelyReferenced_native(const struct HeapObject *);

/// Is this non-null native Swift pointer a unique reference to
/// an object?
bool _swift_isUniquelyReferenced_nonNull_native(const struct HeapObject *);

bool _swift_usesNativeSwiftReferenceCounting_nonNull(const void *);
bool _swift_usesNativeSwiftReferenceCounting_class(const void *);

    __swift_size_t _swift_class_getInstancePositiveExtentSize(const void *);

#ifdef __cplusplus
}} // extern "C", namespace swift
#endif

#endif // SWIFT_STDLIB_SHIMS_RUNTIMESHIMS_H

