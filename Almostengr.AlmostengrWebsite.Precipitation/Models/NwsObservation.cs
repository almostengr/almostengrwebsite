using System;
using System.Collections.Generic;

namespace Almostengr.AlmostengrWebsite.Precipitation
{
    public class NwsObservation
    {
        public List<Feature> Features { get; set; }
    }

    public class Feature
    {
        public Properties Properties { get; set; }
    }

    public class Properties
    {
        public DateTime Timestamp { get; set; }
        public PrecipitationLastHour PrecipitationLastHour { get; set; }
    }

    public class PrecipitationLastHour
    {
        public double? Value { get; set; }
        public string UnitCode { get; set; }
    }
    
    public class Temperature
    {   
        public double? Value { get; set; }
        public string UnitCode { get; set; }
    }
    
    public class RelativeHumidity
    {
        public double? Value { get; set; }
        public string UnitCode { get; set; }
    }
}
