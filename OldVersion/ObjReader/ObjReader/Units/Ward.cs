﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ObjectReader
{
    public enum WardType{
        Regular, Pink
    }
    public class Ward : Unit
    {
        public WardType type { get; private set; }
        internal Ward(int id, int baseAddr, WardType type)
            : base(id, baseAddr)
        {
            this.type = type;
        }
    }
}
