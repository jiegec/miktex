/* ResourceRepository.h:

   Copyright (C) 2020 Christian Schenk

   This file is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 2, or (at your
   option) any later version.

   This file is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this file; if not, write to the Free Software
   Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
   USA. */

#pragma once

#include <cstddef>

struct Resource
{
  const void* data;
  std::size_t len;
};

class ResourceRepository
{
public:
  ResourceRepository();

public:
  ResourceRepository(const ResourceRepository& other) = delete;

public:
  ResourceRepository& operator=(const ResourceRepository& other) = delete;

public:
  ResourceRepository(const ResourceRepository&& other) = delete;

public:
  ResourceRepository& operator=(const ResourceRepository&& other) = delete;

public:
  virtual ~ResourceRepository();

public:
  const Resource& GetResource(const char* resourceId) const;

private:
  void Init();

private:
  void addResource(const char* resourceId, const Resource& resource);

private:
  template<std::size_t N> void R_(const char* resourceId, unsigned char const (&byteArray)[N])
  {
    addResource(resourceId, { byteArray, sizeof(byteArray) });
  }

private:
  class impl;
  impl* pimpl;
};
