using Almostengr.AlmostengrWebsite.Common;

namespace Almostengr.AlmostengrWebsite.Domain.WeatherObservation;

public sealed class NwsDailyObservationDto : BaseDto
{
    public List<Feature>? features { get; set; } 

    // public double? AverageTemperatureC()
    // {
    //     return Features.Where(f => f.Properties.Temperature.Value != null)
    //         .Sum(f => f.Properties.Temperature.Value);
    // }

    // public double? AverageTemperatureF()
    // {
    //     return ConvertCelsiusToFahrenheit(AverageTemperatureC());
    // }

    // public double? MaxTemperatureC()
    // {
    //     return Features.Where(f => f.Properties.Temperature.Value != null)
    //         .Max(f => f.Properties.Temperature.Value);
    // }

    // public double? MinTemperatureC()
    // {
    //     return Features.Where(f => f.Properties.Temperature.Value != null)
    //         .Min(f => f.Properties.Temperature.Value);
    // }

    // public double? MaxTemperatureF()
    // {
    //     return ConvertCelsiusToFahrenheit(MaxTemperatureC());
    // }

    // private double? ConvertCelsiusToFahrenheit(double? temperature)
    // {
    //     if (temperature == null)
    //     {
    //         return null;
    //     }

    //     return (temperature * 1.8) + 32;
    // }

    // public double? PrecipitationSumMeters()
    // {
    //     return Features.Where(f => f.Properties.PrecipitationLastHour.Value != null)
    //         .Sum(f => f.Properties.PrecipitationLastHour.Value);
    // }

    // public double? PrecipitationSumInches()
    // {
    //     return PrecipitationSumMeters() * Constants.MetersToInchesFactor;
    // }

    // public double? MinHumidity()
    // {
    //     return Features.Where(f => f.Properties.RelativeHumidity.Value != null)
    //         .Min(f => f.Properties.RelativeHumidity.Value);
    // }

    // public double? MaxHumidity()
    // {
    //     return Features.Where(f => f.Properties.RelativeHumidity.Value != null)
    //         .Max(f => f.Properties.RelativeHumidity.Value);
    // }

    // public List<Feature> GetYesterdayWeatherData()
    // {
    //     return Features.Where(f => f.Properties.Timestamp.Date == DateTime.Now.AddDays(-1)).ToList();
    // }

    // public string ProcessCsvData()
    // {
    //     const string unit = "unit:";
    //     const string separator = ",";
    //     StringBuilder sb = new(); 

    //     foreach (Feature feature in Features)
    //     {
    //         sb.Append(feature.Properties.Timestamp.ToString("yyyy-MM-dd HH:mm:ss"));
    //         sb.Append(separator);
    //         sb.Append(feature.Properties.Temperature.Value);
    //         sb.Append(separator);
    //         sb.Append(feature.Properties.Temperature.UnitCode.Replace(unit, string.Empty));
    //         sb.Append(separator);
    //         sb.Append((string.IsNullOrEmpty(feature.Properties.PrecipitationLastHour.Value.ToString()) ? 0 : feature.Properties.PrecipitationLastHour.Value));
    //         sb.Append(separator);
    //         sb.Append(feature.Properties.PrecipitationLastHour.UnitCode.Replace(unit, string.Empty));
    //         sb.Append(separator);
    //         sb.Append(feature.Properties.RelativeHumidity.Value);
    //         sb.Append(separator);
    //         sb.Append(feature.Properties.RelativeHumidity.UnitCode.Replace(unit, string.Empty));
    //         sb.Append(separator);
    //     }

    //     return sb.ToString();
    // }

    // public string ProcessBlogPostData()
    // {
    //     string reportDate = Features.First().Properties.Timestamp.ToString("yyyy-MM-dd");
    //     const string separator = "|";
    //     const string temperatureFormat = "{0:N1}";
    //     const string humidityFormat = "{0:N0}";
    //     const string precipitationFormat = "{0:N3}";

    //     StringBuilder text = new StringBuilder(reportDate);
    //     text.Append(separator);
    //     text.Append(string.Format(temperatureFormat, MinTemperatureC()));
    //     text.Append(" (" + string.Format(temperatureFormat, MinTemperatureF()) + ")");
    //     text.Append(separator);
    //     text.Append(string.Format(temperatureFormat, MaxTemperatureC()));
    //     text.Append(" (" + string.Format(temperatureFormat, MaxTemperatureF()) + ")");
    //     text.Append(separator);
    //     text.Append(string.Format(temperatureFormat, AverageTemperatureC()));
    //     text.Append(" (" + string.Format(temperatureFormat, AverageTemperatureF()) + ")");
    //     text.Append(separator);
    //     text.Append(string.Format(humidityFormat, MinHumidity()));
    //     text.Append(separator);
    //     text.Append(string.Format(humidityFormat, MaxHumidity()));
    //     text.Append(separator);
    //     text.Append(string.Format(humidityFormat, AverageHumidity()));
    //     text.Append(separator);
    //     text.Append(string.Format(precipitationFormat, PrecipitationSumMeters()));
    //     text.Append(" (" + string.Format(precipitationFormat, PrecipitationSumInches()) + ")");
    //     text.Append(separator);
    //     text.Append(string.Format(precipitationFormat, PrecipitationAveragePerHourMeters()));
    //     text.Append(" (" + string.Format(precipitationFormat, PrecipitationAveragePerHourInches()) + ")");
    //     text.Append(separator);
    //     return text.ToString();
    // }

    // public double? PrecipitationAveragePerHourInches()
    // {
    //     return PrecipitationAveragePerHourMeters() * Constants.MetersToInchesFactor;
    // }

    // public double? PrecipitationAveragePerHourMeters()
    // {
    //     return Features.Where(f => f.Properties.PrecipitationLastHour.Value != null)
    //         .Average(f => f.Properties.PrecipitationLastHour.Value);
    // }

    // public double? AverageHumidity()
    // {
    //     return Features.Where(f => f.Properties.RelativeHumidity.Value != null)
    //         .Average(f => f.Properties.RelativeHumidity.Value);
    // }

    // public double? MinTemperatureF()
    // {
    //     return ConvertCelsiusToFahrenheit(MinTemperatureC());
    // }
}

public sealed class Feature
{
    public Properties properties { get; set; } 
}

public sealed class Properties
{
    public DateTime Timestamp { get; set; }
    public PrecipitationLastHour PrecipitationLastHour { get; set; } 
    public Temperature Temperature { get; set; } 
    public RelativeHumidity RelativeHumidity { get; set; } 
}

public sealed class PrecipitationLastHour
{
    public double? Value { get; set; } = 0.0;
    public string UnitCode { get; set; } = "m";
}

public sealed class Temperature
{
    public double? Value { get; set; }
    public string UnitCode { get; set; } = "C";
}

public sealed class RelativeHumidity
{
    public double? Value { get; set; }
    public string UnitCode { get; set; }
};
