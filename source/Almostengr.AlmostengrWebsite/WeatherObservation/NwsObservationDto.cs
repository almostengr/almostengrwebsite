using System.Text;

namespace Almostengr.AlmostengrWebsite.WeatherObservation;

public sealed record NwsDailyObservationDto
{
    public List<Feature> Features { get; private set; } = new();

    // internal NwsObservationEntity ToEntity()
    // {
    //     if (this.Features == null)
    //     {
    //         throw new NwsObservationDtoIsNullException();
    //     }

    //     return new NwsObservationEntity();
    // }

    // public void AddTemperatureReading(double? temperature)
    // {
    //     if (temperature == null)
    //     {
    //         return;
    //     }

    //     TemperatureReadings.Add((double)temperature);
    // }

    internal double? AverageTemperatureC()
    {
        // double sum = 0.0;
        // int counter = 0;

        // foreach (var feature in Features)
        // {
        //     if (feature.Properties.Temperature.Value == null)
        //     {
        //         continue;
        //     }

        //     sum = (double)feature.Properties.Temperature.Value;
        //     counter++;
        // }

        // return sum / counter;
        return Features.Where(f => f.Properties.Temperature.Value != null)
            .Sum(f => f.Properties.Temperature.Value);
    }

    internal double? AverageTemperatureF()
    {
        return ConvertCelsiusToFahrenheit(AverageTemperatureC());
    }

    internal double? MaxTemperatureC()
    {
        // double? highestTemperature = null;

        // foreach (var feature in Features)
        // {
        //     if (feature.Properties.Temperature.Value == null)
        //     {
        //         continue;
        //     }

        //     if (feature.Properties.Temperature.Value > highestTemperature)
        //     {
        //         highestTemperature = feature.Properties.Temperature.Value;
        //     }
        // }

        // return highestTemperature;

        return Features.Where(f => f.Properties.Temperature.Value != null)
            .Max(f => f.Properties.Temperature.Value);
    }

    internal double? MinTemperatureC()
    {
        // double? lowestTemperature = null;

        // foreach (var feature in Features)
        // {
        //     if (feature.Properties.Temperature.Value == null)
        //     {
        //         continue;
        //     }

        //     if (lowestTemperature < feature.Properties.Temperature.Value)
        //     {
        //         lowestTemperature = feature.Properties.Temperature.Value;
        //     }
        // }

        // return lowestTemperature;

        return Features.Where(f => f.Properties.Temperature.Value != null)
            .Min(f => f.Properties.Temperature.Value);
    }

    internal double? MaxTemperatureF()
    {
        return ConvertCelsiusToFahrenheit(MaxTemperatureC());
    }

    // public double MinTemperatureF()
    // {
    //     return ConvertCelsiusToFahrenheit(TemperatureReadings.Min());
    // }

    private double? ConvertCelsiusToFahrenheit(double? temperature)
    {
        if (temperature == null)
        {
            return null;
        }

        return (temperature * 1.8) + 32;
    }

    // internal void AddHumidityReading(double? value)
    // {
    //     if (value == null)
    //     {
    //         return;
    //     }

    //     HumidityReadings.Add((double)value);
    // }

    // internal void AddPreciptationReading(double? value)
    // {
    //     if (value == null)
    //     {
    //         value = 0;
    //     }

    //     PrecipitationReadings.Add((double)value);
    // }

    internal double? PrecipitationSum()
    {
        // double sum = 0;
        // foreach (var feature in Features)
        // {
        //     if (feature.Properties.PrecipitationLastHour.Value == null)
        //     {
        //         continue;
        //     }

        //     sum += (double)feature.Properties.PrecipitationLastHour.Value;
        // }

        // return sum;
        return Features.Where(f => f.Properties.PrecipitationLastHour.Value != null)
            .Sum(f => f.Properties.PrecipitationLastHour.Value);
    }

    internal double? PrecipitationSumInches()
    {
        return PrecipitationSum() * Constants.MetersToInchesFactor;
    }

    // internal double PrecipitationAveragePerHour()
    // {
    //     return PrecipitationReadings.Sum() / PrecipitationReadings.Count();
    // }

    // internal double PrecipitationAveragePerHourInches()
    // {
    //     return (PrecipitationReadings.Sum() * Constants.MetersToInchesFactor) / PrecipitationReadings.Count();
    // }

    internal double? MinHumidity()
    {
        // return HumidityReadings.Min();
        // double? humidity = null;
        // foreach (var feature in Features)
        // {
        //     if (feature.Properties.RelativeHumidity.Value == null)
        //     {
        //         continue;
        //     }

        //     if (feature.Properties.RelativeHumidity.Value < humidity)
        //     {
        //         humidity = feature.Properties.RelativeHumidity.Value;
        //     }
        // }

        // return humidity;
        return Features.Where(f => f.Properties.RelativeHumidity.Value != null)
            .Min(f => f.Properties.RelativeHumidity.Value);
    }

    internal double? MaxHumidity()
    {
        // double? humidity = null;
        // foreach (var feature in Features)
        // {
        //     if (feature.Properties.RelativeHumidity.Value == null)
        //     {
        //         continue;
        //     }

        //     if (feature.Properties.RelativeHumidity.Value > humidity)
        //     {
        //         humidity = feature.Properties.RelativeHumidity.Value;
        //     }
        // }

        // return humidity;
        return Features.Where(f => f.Properties.RelativeHumidity.Value != null)
            .Max(f => f.Properties.RelativeHumidity.Value);
    }

    // internal double AverageHumidity()
    // {
    //     return HumidityReadings.Sum() / HumidityReadings.Count();
    // }

    internal List<Feature> GetYesterdayWeatherData()
    {
        // List<Feature> yesterdayData = new List<Feature>();
        DateTime currentDate = DateTime.Now;

        // foreach (var feature in Features)
        // {
        //     if (feature.Properties.Timestamp.Date == currentDate.AddDays(-1))
        //     {
        //         yesterdayData.Add(feature);
        //     }
        // }

        // if (yesterdayData.Count == 0)
        // {
        //     throw new NwsObservationYesterDayCountZeroException();
        // }

        return Features.Where(f => f.Properties.Timestamp.Date == currentDate.AddDays(-1)).ToList();
        // return yesterdayData;
    }


    // internal NwsDailyObservationEntity YesterdayWeatherDataAsEntity()
    // {
    //     // List<Feature> yesterdayData = new List<Feature>();
    //     NwsDailyObservationEntity observationEntity = new();
    //     DateTime currentDate = DateTime.Now;

    //     if (Features.Count == 0)
    //     {
    //         throw new NwsObservationYesterDayCountZeroException();
    //     }

    //     foreach (var feature in Features)
    //     {
    //         if (feature.Properties.Timestamp.Date == currentDate.AddDays(-1))
    //         {
    //             // yesterdayData.Add(feature);
    //             observationEntity.AddHumidityReading(feature.Properties.RelativeHumidity.Value);
    //             observationEntity.AddPreciptationReading(feature.Properties.PrecipitationLastHour.Value);
    //             observationEntity.AddTemperatureReading(feature.Properties.Temperature.Value);
    //         }
    //     }

    //     // return yesterdayData;
    //     return observationEntity;
    // }

    internal string ProcessCsvData()
    {
        const string separator = ",";
        StringBuilder sb = new();

        foreach (Feature feature in Features)
        {
            sb.Append(feature.Properties.Timestamp.ToString("yyyy-MM-dd HH:mm:ss"));
            sb.Append(separator);
            sb.Append(feature.Properties.Temperature.Value);
            sb.Append(separator);
            sb.Append(feature.Properties.Temperature.UnitCode.Replace("unit:", ""));
            sb.Append(separator);
            sb.Append((string.IsNullOrEmpty(feature.Properties.PrecipitationLastHour.Value.ToString()) ? 0 : feature.Properties.PrecipitationLastHour.Value));
            sb.Append(separator);
            sb.Append(feature.Properties.PrecipitationLastHour.UnitCode.Replace("unit:", ""));
            sb.Append(separator);
            sb.Append(feature.Properties.RelativeHumidity.Value);
            sb.Append(separator);
            sb.Append(feature.Properties.RelativeHumidity.UnitCode.Replace("unit:", ""));
            sb.Append(separator);
        }

        return sb.ToString();
    }

    // internal List<string> ProcessBlogPostData()
    internal string ProcessBlogPostData()
    {
        // DateTime feature = 
        string reportDate = Features.First().Properties.Timestamp.ToString("yyyy-MM-dd");

        // foreach (var feature in Features)
        // {
        //     reportDate = new DateTime(
        //         feature.Properties.Timestamp.Year,
        //         feature.Properties.Timestamp.Month,
        //         feature.Properties.Timestamp.Day)
        //         .ToString("yyyy-MM-dd");
        //     break;
        // }

        // double? sumTemperature = 0.0;
        // double? maxTemperature = null;
        // double? minTemperature = null;

        // double? sumHumidity = 0.0;
        // double? maxHumidity = null;
        // double? minHumidity = null;

        // double? sumPrecipM = 0.0;

        // NwsDailyObservationEntity observationEntity = new NwsDailyObservationEntity();

        // foreach (var feature in Features)
        // {
        //     // temperature

        //     observationEntity.AddTemperatureReading(feature.Properties.Temperature.Value);

        //     // observationEntity.SetMaxTempC(feature.Properties.Temperature.Value);
        //     // observationEntity.SetMinTempC(feature.Properties.Temperature.Value);
        //     // maxTemperature = (maxTemperature == null || feature.Properties.Temperature.Value > maxTemperature) ?
        //     //     feature.Properties.Temperature.Value : maxTemperature;
        //     // minTemperature = (minTemperature == null || feature.Properties.Temperature.Value < minTemperature) ?
        //     //     feature.Properties.Temperature.Value : minTemperature;
        //     // sumTemperature += feature.Properties.Temperature.Value;

        //     // humidity

        //     // maxHumidity = (maxHumidity == null || feature.Properties.RelativeHumidity.Value > maxHumidity) ?
        //     //     feature.Properties.RelativeHumidity.Value : maxHumidity;
        //     // minHumidity = (minHumidity == null || feature.Properties.RelativeHumidity.Value < minHumidity) ?
        //     //     feature.Properties.RelativeHumidity.Value : minHumidity;
        //     // observationEntity.SetMaxHumidity(feature.Properties.RelativeHumidity.Value);
        //     // observationEntity.SetMinHumidity(feature.Properties.RelativeHumidity.Value);
        //     // sumHumidity += feature.Properties.RelativeHumidity.Value;

        //     observationEntity.AddHumidityReading(feature.Properties.RelativeHumidity.Value);

        //     // precipitation

        //     // sumPrecipM += feature.Properties.PrecipitationLastHour.Value > 0 ? feature.Properties.PrecipitationLastHour.Value : 0;
        //     observationEntity.AddPreciptationReading(feature.Properties.PrecipitationLastHour.Value);
        // }

        // double? sumPrecipInch = sumPrecipM * 39.370078740157;

        const string separator = "|";
        StringBuilder text = new StringBuilder(reportDate);
        text.Append(separator);
        // text.Append()

        // string line = "|";
        // line += reportDate;
        // line += "|";
        const string temperatureFormat = "{0:N1}";
        const string humidityFormat = "{0:N0}";
        const string precipitationFormat = "{0:N3}";

        text.Append(string.Format(temperatureFormat, MinTemperatureC()));
        text.Append(" (" + string.Format(temperatureFormat, MinTemperatureF()) + ")");
        text.Append(separator);
        text.Append(string.Format(temperatureFormat, MaxTemperatureC()));
        text.Append(" (" + string.Format(temperatureFormat, MaxTemperatureF()) + ")");
        text.Append(separator);
        text.Append(string.Format(temperatureFormat, AverageTemperatureC()));
        text.Append(" (" + string.Format(temperatureFormat, AverageTemperatureF()) + ")");
        text.Append(separator);
        text.Append(string.Format(humidityFormat, MinHumidity()));
        text.Append(separator);
        text.Append(string.Format(humidityFormat, MaxHumidity()));
        text.Append(separator);
        text.Append(string.Format(humidityFormat, AverageHumidity()));
        text.Append(separator);
        text.Append(string.Format(precipitationFormat, PrecipitationSum()));
        text.Append(" (" + string.Format(precipitationFormat, PrecipitationSumInches()) + ")");
        text.Append(separator);
        text.Append(string.Format(precipitationFormat, PrecipitationAveragePerHour()));
        text.Append(" (" + string.Format(precipitationFormat, PrecipitationAveragePerHourInches()) + ")");
        text.Append(separator);

        // text.Add(line);

        // return text;
        return text.ToString();
    }

    internal double? PrecipitationAveragePerHourInches()
    {
        return PrecipitationAveragePerHour() * Constants.MetersToInchesFactor;
    }

    internal double? PrecipitationAveragePerHour()
    {
        return Features.Where(f => f.Properties.PrecipitationLastHour.Value != null)
            .Average(f => f.Properties.PrecipitationLastHour.Value);
    }

    internal double? AverageHumidity()
    {
        return Features.Where(f => f.Properties.RelativeHumidity.Value != null)
            .Average(f => f.Properties.RelativeHumidity.Value);
    }

    internal double? MinTemperatureF()
    {
        return ConvertCelsiusToFahrenheit(MinTemperatureC());
    }
}

public sealed record Feature
{
    public Properties Properties { get; private set; } = new();
}

public sealed record Properties
{
    public DateTime Timestamp { get; private set; }
    public PrecipitationLastHour PrecipitationLastHour { get; private set; } = new();
    public Temperature Temperature { get; private set; } = new();
    public RelativeHumidity RelativeHumidity { get; private set; } = new();
}

public sealed record PrecipitationLastHour
{
    public double? Value { get; private set; } = 0.0;
    public string UnitCode { get; private set; } = string.Empty;
}

public sealed record Temperature
{
    public double? Value { get; private set; } = 0.0;
    public string UnitCode { get; private set; } = string.Empty;
}

public sealed record RelativeHumidity
{
    public double? Value { get; private set; } = 0.0;
    public string UnitCode { get; private set; } = string.Empty;
};
