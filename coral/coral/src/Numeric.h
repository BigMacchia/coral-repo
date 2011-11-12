// <license>
// Copyright (C) 2011 Andrea Interguglielmi, All rights reserved.
// This file is part of the coral repository downloaded from http://code.google.com/p/coral-repo.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
// 
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
// 
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// </license>



#ifndef NUMERIC_H
#define NUMERIC_H

#include <cstdio> 
#include <vector>

#include <ImathVec.h>
#include <ImathColor.h>
#include <ImathMatrix.h>
#include <ImathQuat.h>

#include "Value.h"

namespace coral{

class NumericOperation;

//! A dynamic class that wraps all the available numerical types, used by NumericAttribute.
class CORAL_EXPORT Numeric : public Value{

public:
	enum Type{
		numericTypeAny = 0,
		numericTypeInt,
		numericTypeIntArray,
		numericTypeFloat,
		numericTypeFloatArray,
		numericTypeVec3,
		numericTypeVec3Array,
		numericTypeCol4,
		numericTypeCol4Array,
		numericTypeQuat,
		numericTypeQuatArray,
		numericTypeMatrix44,
		numericTypeMatrix44Array
	};

	Numeric();
	void copy(const Value *other);
	Numeric::Type type();
	void setType(Numeric::Type type);
	bool isArray();
	unsigned int size();
	void resize(unsigned int newSize);
	void setIntValueAt(unsigned int id, int value);
	void setFloatValueAt(unsigned int id, float value);
	void setVec3ValueAt(unsigned int id, const Imath::V3f &value);
	void setCol4ValueAt(unsigned int id, const Imath::Color4f &value);
	void setQuatValueAt(unsigned int id, const Imath::Quatf &value);
	void setMatrix44ValueAt(unsigned int id, const Imath::M44f &value);
	const std::vector<int> &intValues();
	const std::vector<float> &floatValues();
	const std::vector<Imath::V3f> &vec3Values();
	const std::vector<Imath::Color4f> &col4Values();
	const std::vector<Imath::Quatf> &quatValues();
	const std::vector<Imath::M44f> &matrix44Values();
	int intValueAt(unsigned int id);
	float floatValueAt(unsigned int id);
	Imath::V3f vec3ValueAt(unsigned int id);
	Imath::Color4f col4ValueAt(unsigned int id);
	Imath::Quatf quatValueAt(unsigned int id);
	Imath::M44f matrix44ValueAt(unsigned int id);
	void setIntValues(const std::vector<int> &values);
	void setFloatValues(const std::vector<float> &values);
	void setVec3Values(const std::vector<Imath::V3f> &values);
	void setCol4Values(const std::vector<Imath::Color4f> &values);
	void setQuatValues(const std::vector<Imath::Quatf> &values);
	void setMatrix44Values(const std::vector<Imath::M44f> &values);
	bool isArrayType(Numeric::Type type);
	std::string asString();
	void setFromString(const std::string &value);
	
private:
	friend class NumericOperation;
	
	std::vector<int> _intValues;
	std::vector<float> _floatValues;
	std::vector<Imath::V3f > _vec3Values;
	std::vector<Imath::Color4f > _col4Values;
	std::vector<Imath::Quatf > _quatValues;
	std::vector<Imath::M44f > _matrix44Values;
	bool _isArray;
	Type _type;	
	unsigned int _size;
};

}
#endif

