using System;
using System.Collections.Generic;

namespace Almostengr.AlmostengrWebsite.Common.GardeningData.DomainServices.Resources;

public class NwsObservationResource
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
    public PrecipitationLastHour PrecipitationLast3Hours { get; set; }
    public Temperature Temperature { get; set; }
    public RelativeHumidity RelativeHumidity { get; set; }
}

public class PrecipitationLastHour
{
    public double? Value { get; set; } = 0.0;
    public string UnitCode { get; set; }
}

public class Temperature
{
    public double? Value { get; set; } = 0.0;
    public string UnitCode { get; set; }
}

public class RelativeHumidity
{
    public double? Value { get; set; } = 0.0;
    public string UnitCode { get; set; }
}
